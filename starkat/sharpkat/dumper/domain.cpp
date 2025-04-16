

#include "domain.h"

#include "../api/il2cpp_functions.h"
#include "../util/logger.h"

#include <fstream>

#include "assembly.h"
#include "../entry.h"

namespace cs {
namespace dump {
    void dump() {
        il2cpp_functions funcs;

        settings.class_byval = brute_class_byval(&funcs);

        Il2CppDomain* domain = funcs.il2cpp_domain_get();

        if (domain == nullptr) {
            Logger::Error("il2cppdomain is null");
        }

        size_t assemblyCount = 0;
        size_t classCount = 0;
        Il2CppAssembly** assemblies = funcs.il2cpp_domain_get_assemblies(domain, &assemblyCount);
        std::ofstream stream("dump.cs");

        for (int i = 0; i < assemblyCount; i++) {
            Il2CppImage* image = funcs.il2cpp_assembly_get_image(assemblies[i]);
            stream << "// Assembly #" << i << ": " << funcs.il2cpp_image_get_name(image) << "\n";
            classCount += funcs.il2cpp_image_get_class_count(image);
        }

        stream << "\n";

        Logger::Info("Dumping " + std::to_string(classCount) + " classes in " + std::to_string(assemblyCount) + " assemblies!");

        for (int i = 0; i < assemblyCount; i++) {
            dump_assembly(&funcs, assemblies[i], i, &stream);
        }
    }
} // dump
} // cs