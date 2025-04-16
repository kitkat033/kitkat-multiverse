

#ifndef METHODS_H
#define METHODS_H
#include <fstream>

#include "../api/il2cpp_functions.h"

namespace cs {
namespace dump {
    void dump_methods(il2cpp_functions* funcs, Il2CppClass* klass, std::ofstream* stream);
} // dump
} // cs

#endif //METHODS_H
