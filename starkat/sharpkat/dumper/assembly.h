

#ifndef ASSEMBLY_H
#define ASSEMBLY_H
#include <fstream>

#include "../api/il2cpp_functions.h"

namespace cs {
namespace dump {
    void dump_assembly(il2cpp_functions* funcs, Il2CppAssembly* assembly, int assemblyIndex, std::ofstream* stream);
} // dump
} // cs

#endif //ASSEMBLY_H
