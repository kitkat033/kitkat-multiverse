

#ifndef FIELDS_H
#define FIELDS_H
#include <fstream>

#include "../api/il2cpp_functions.h"

namespace cs {
namespace dump {
    const char* convert_primitive_type(const char *typeName);
    void dump_fields(il2cpp_functions* funcs, Il2CppClass* klass, std::ofstream* stream);
} // dump
} // cs

#endif //FIELDS_H
