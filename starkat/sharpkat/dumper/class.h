

#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <fstream>

#include "../api/il2cpp_functions.h"

namespace cs {
namespace dump {
    void get_class_modifiers(Il2CppClass* klass, il2cpp_functions* funcs, std::ofstream* dump);
} // dump
} // cs

#endif //TYPE_H
