

#ifndef ENTRY_H
#define ENTRY_H

#include <cstdint>
#include <windows.h>

#include "api/il2cpp_functions.h"

struct Settings {
    uintptr_t up;
    uintptr_t ga;

    uintptr_t il2cpp_init;
    size_t class_byval;
};

namespace cs {
    extern Settings settings;

    size_t brute_class_byval(cs::il2cpp_functions* funcs);
    DWORD main(LPVOID hMod);
} // cs

#endif //ENTRY_H
