

#include "methods.h"

#include "fields.h"

namespace cs {
namespace dump {
    const char* short_type_name(Il2CppType* type, il2cpp_functions* funcs) { // FAILS SOMETIMES, TODO REWRITE!
        //const char *full_type_name = convert_primitive_type(funcs->il2cpp_type_get_name(type));
        //const char *dot = strrchr(full_type_name, '.');
        //return dot ? dot + 1 : full_type_name;
        return convert_primitive_type(funcs->il2cpp_type_get_name(type));
    }

    void dump_methods(il2cpp_functions *funcs, Il2CppClass *klass, std::ofstream *stream) {
        MethodInfo* method;
        void* iter = 0;

        while ((method = funcs->il2cpp_class_get_methods(klass, &iter))) {
            const char* name = funcs->il2cpp_method_get_name(method);
            const char *full_type_name = convert_primitive_type(funcs->il2cpp_type_get_name(funcs->il2cpp_method_get_return_type(method)));
            const char *dot = strrchr(full_type_name, '.');
            const char *type_name = dot ? dot + 1 : full_type_name;

            *stream << "\t" << type_name << " " << name << "(";

            bool first = true;
            for (int i = 0; i < funcs->il2cpp_method_get_param_count(method); i++) {
                Il2CppType* param = funcs->il2cpp_method_get_param(method, i);
                if (!first) {
                    *stream << ", ";
                }
                *stream << short_type_name(param, funcs) << " param" << i;
                first = false;
            }

            *stream << ") { } // RVA: 0x" << std::hex << funcs->il2cpp_method_get_relative_pointer(method) << std::dec << "\n";
        }
    }

} // dump
} // cs