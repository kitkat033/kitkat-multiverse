#include "entry.h"

#include <windows.h>
#include "util/logger.h"
#include "util/mem.h"
#include <psapi.h>

#include "api/il2cpp_functions.h"
#include "dumper/domain.h"

#pragma comment(lib, "psapi.lib")

size_t GetModuleSize(HMODULE hModule) {
    MODULEINFO modInfo = {};
    if (GetModuleInformation(GetCurrentProcess(), hModule, &modInfo, sizeof(modInfo))) {
        return modInfo.SizeOfImage;
    }
    return 0;
}

uintptr_t ExtractQwordTarget(uintptr_t instruction_address) {
    int32_t relative_offset = *reinterpret_cast<int32_t*>(instruction_address + 3);
    uintptr_t next_instruction = instruction_address + 7;
    uintptr_t target_address = next_instruction + relative_offset;
    return target_address;
}

namespace cs {
    Settings settings;

    uintptr_t retrieve_il2cpp_init() {
        uintptr_t out = scan(settings.up, GetModuleSize(reinterpret_cast<HMODULE>(settings.up)), "48 8B 05 ? ? ? ? 48 8D 0D ? ? ? ? FF D0");

        if (out != 0) {
            out = ExtractQwordTarget(out);
        }
        return out;
    }

    size_t brute_class_byval(il2cpp_functions* funcs) {
        Il2CppDomain* domain = funcs->il2cpp_domain_get();
        size_t assemblyCount = 0;
        Il2CppAssembly** assemblies = funcs->il2cpp_domain_get_assemblies(domain, &assemblyCount);

        if (assemblyCount == 0) return 0;

        Il2CppImage* image = funcs->il2cpp_assembly_get_image(assemblies[0]);
        Il2CppClass* klass = funcs->il2cpp_image_get_class(image, 0);
        printf("%llX\n", klass);
        size_t offset = 0;
        for (offset = 0; offset < 256; offset += sizeof(void*)) {
            __try { // sigh seh HAHA GET IT BEC-
                uintptr_t ptr = ((uintptr_t)klass + offset);
                Il2CppType* type = (Il2CppType*)ptr;

                const char* typeName = funcs->il2cpp_type_get_name(type);

                if (typeName != nullptr) {
                    return offset;
                }
            }
            __except (EXCEPTION_EXECUTE_HANDLER) {
                // lmao
            }
        }

        return 0;
    }

    DWORD main(LPVOID hMod) {
        Logger::Init();
        Logger::Info("Waiting for HSR to start...");

        while (true) {
            settings.ga = reinterpret_cast<uintptr_t>(GetModuleHandleA("GameAssembly.dll"));
            settings.up = reinterpret_cast<uintptr_t>(GetModuleHandleA("UnityPlayer.dll"));

            if (settings.ga != 0 && settings.up != 0)
                break;

            Sleep(2000);
        }

        settings.il2cpp_init = retrieve_il2cpp_init();

        if (settings.il2cpp_init == 0) {
            Logger::Error("Could not load il2cpp api.");
            return FALSE;
        }

        Logger::Info("Waiting some seconds before dumping...");
        Sleep(10000);

        dump::dump(); // ah yes, redundancy

        return TRUE;
    }
} // cs