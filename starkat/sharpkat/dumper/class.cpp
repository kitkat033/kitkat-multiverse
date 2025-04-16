

#include "class.h"

namespace cs {
namespace dump {
    void get_class_modifiers(Il2CppClass *klass, il2cpp_functions* funcs, std::ofstream* dump) {
        uint32_t flags = funcs->il2cpp_class_get_flags(klass);

        if (flags & TYPE_ATTRIBUTE_PUBLIC || flags & TYPE_ATTRIBUTE_NESTED_PUBLIC) {
            *dump << "public ";
        } else if (flags & TYPE_ATTRIBUTE_NESTED_FAM_OR_ASSEM) {
            *dump << "protected internal ";
        } else if (flags & TYPE_ATTRIBUTE_NESTED_FAMILY) {
            *dump << "protected ";
        } else if (flags & TYPE_ATTRIBUTE_NESTED_ASSEMBLY) {
            *dump << "internal ";
        } else if (flags & TYPE_ATTRIBUTE_NESTED_FAM_AND_ASSEM) {
            *dump << "private protected ";
        } else if (flags & TYPE_ATTRIBUTE_NESTED_PRIVATE) {
            *dump << "private ";
        }

        // Other modifiers
        if (flags & TYPE_ATTRIBUTE_ABSTRACT) {
            *dump << "abstract ";
        }

        if (flags & TYPE_ATTRIBUTE_INTERFACE) {
            *dump << "interface ";
        } else if (funcs->il2cpp_class_is_enum(klass)) {
            *dump << "enum ";
        } else if (funcs->il2cpp_class_is_valuetype(klass)) {
            *dump << "struct ";
        } else {
            *dump << "class ";
        }
    }

} // dump
} // cs