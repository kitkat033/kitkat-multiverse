

#include "fields.h"

#include <sstream>
#include "../entry.h"

namespace cs {
namespace dump {
    const char* convert_primitive_type(const char *typeName)
    {
        if (strcmp(typeName, "System.Boolean") == 0) {
            return "bool";
        }  if (strcmp(typeName, "System.String") == 0) {
            return "string";
        }  if (strcmp(typeName, "System.Void") == 0) {
            return "void";
        }  if (strcmp(typeName, "System.Byte") == 0) {
            return "byte";
        }  if (strcmp(typeName, "System.SByte") == 0) {
            return "sbyte";
        }  if (strcmp(typeName, "System.Char") == 0) {
            return "char";
        }  if (strcmp(typeName, "System.Decimal") == 0) {
            return "decimal";
        }  if (strcmp(typeName, "System.Double") == 0) {
            return "double";
        }  if (strcmp(typeName, "System.Single") == 0) {
            return "float";
        }  if (strcmp(typeName, "System.Int32") == 0) {
            return "int";
        }  if (strcmp(typeName, "System.UInt32") == 0) {
            return "uint";
        }  if (strcmp(typeName, "System.IntPtr") == 0) {
            return "nint";
        }  if (strcmp(typeName, "System.UIntPtr") == 0) {
            return "nuint";
        }  if (strcmp(typeName, "System.Int64") == 0) {
            return "long";
        }  if (strcmp(typeName, "System.UInt64") == 0) {
            return "ulong";
        }  if (strcmp(typeName, "System.Int16") == 0) {
            return "short";
        }  if (strcmp(typeName, "System.UInt16") == 0) {
            return "ushort";
        }

        return typeName;
    }

    std::string get_field_flags(FieldInfo* field, il2cpp_functions* funcs) {
        uint32_t attrs = funcs->il2cpp_field_get_flags(field);
        auto access = attrs & FIELD_ATTRIBUTE_FIELD_ACCESS_MASK;

        std::stringstream ss;

        switch (access) {
            case FIELD_ATTRIBUTE_PRIVATE:
                ss << "private ";
            break;
            case FIELD_ATTRIBUTE_PUBLIC:
                ss << "public ";
            break;
            case FIELD_ATTRIBUTE_FAMILY:
                ss << "protected ";
            break;
            case FIELD_ATTRIBUTE_ASSEMBLY:
            case FIELD_ATTRIBUTE_FAM_AND_ASSEM:
                ss << "internal ";
            break;
            case FIELD_ATTRIBUTE_FAM_OR_ASSEM:
                ss << "protected internal ";
            break;
        }
        if (attrs & FIELD_ATTRIBUTE_LITERAL) {
            ss << "const ";
        } else {
            if (attrs & FIELD_ATTRIBUTE_STATIC) {
                ss << "static ";
            }
            if (attrs & FIELD_ATTRIBUTE_INIT_ONLY) {
                ss << "readonly ";
            }
        }

        return ss.str();
    }

    void dump_fields(il2cpp_functions *funcs, Il2CppClass *klass, std::ofstream *stream) {
        FieldInfo* field;
        void* iter = 0;

        while ((field = funcs->il2cpp_class_get_fields(klass, &iter))) {
            const char* name = funcs->il2cpp_field_get_name(field);
            const char *full_type_name = convert_primitive_type(funcs->il2cpp_type_get_name(funcs->il2cpp_field_get_type(field)));
            const char *dot = strrchr(full_type_name, '.');
            const char *type_name = dot ? dot + 1 : full_type_name;
            size_t offset = funcs->il2cpp_field_get_offset(field);


            *stream << "\t" << get_field_flags(field, funcs).c_str() << type_name << " " << name << "; // 0x" << std::hex << offset << std::dec << "\n";
        }
    }

} // dump
} // cs