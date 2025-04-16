#ifndef CS_IL2CPP_FUNCTIONS_H
#define CS_IL2CPP_FUNCTIONS_H

#include <cstdint>
#include <cstddef>

/*
 * Field Attributes (21.1.5).
 */

#define FIELD_ATTRIBUTE_FIELD_ACCESS_MASK     0x0007
#define FIELD_ATTRIBUTE_COMPILER_CONTROLLED   0x0000
#define FIELD_ATTRIBUTE_PRIVATE               0x0001
#define FIELD_ATTRIBUTE_FAM_AND_ASSEM         0x0002
#define FIELD_ATTRIBUTE_ASSEMBLY              0x0003
#define FIELD_ATTRIBUTE_FAMILY                0x0004
#define FIELD_ATTRIBUTE_FAM_OR_ASSEM          0x0005
#define FIELD_ATTRIBUTE_PUBLIC                0x0006

#define FIELD_ATTRIBUTE_STATIC                0x0010
#define FIELD_ATTRIBUTE_INIT_ONLY             0x0020
#define FIELD_ATTRIBUTE_LITERAL               0x0040
#define FIELD_ATTRIBUTE_NOT_SERIALIZED        0x0080
#define FIELD_ATTRIBUTE_SPECIAL_NAME          0x0200
#define FIELD_ATTRIBUTE_PINVOKE_IMPL          0x2000

/* For runtime use only */
#define FIELD_ATTRIBUTE_RESERVED_MASK         0x9500
#define FIELD_ATTRIBUTE_RT_SPECIAL_NAME       0x0400
#define FIELD_ATTRIBUTE_HAS_FIELD_MARSHAL     0x1000
#define FIELD_ATTRIBUTE_HAS_DEFAULT           0x8000
#define FIELD_ATTRIBUTE_HAS_FIELD_RVA         0x0100

/*
 * Method Attributes (22.1.9)
 */

#define METHOD_IMPL_ATTRIBUTE_CODE_TYPE_MASK       0x0003
#define METHOD_IMPL_ATTRIBUTE_IL                   0x0000
#define METHOD_IMPL_ATTRIBUTE_NATIVE               0x0001
#define METHOD_IMPL_ATTRIBUTE_OPTIL                0x0002
#define METHOD_IMPL_ATTRIBUTE_RUNTIME              0x0003

#define METHOD_IMPL_ATTRIBUTE_MANAGED_MASK         0x0004
#define METHOD_IMPL_ATTRIBUTE_UNMANAGED            0x0004
#define METHOD_IMPL_ATTRIBUTE_MANAGED              0x0000

#define METHOD_IMPL_ATTRIBUTE_FORWARD_REF          0x0010
#define METHOD_IMPL_ATTRIBUTE_PRESERVE_SIG         0x0080
#define METHOD_IMPL_ATTRIBUTE_INTERNAL_CALL        0x1000
#define METHOD_IMPL_ATTRIBUTE_SYNCHRONIZED         0x0020
#define METHOD_IMPL_ATTRIBUTE_NOINLINING           0x0008
#define METHOD_IMPL_ATTRIBUTE_MAX_METHOD_IMPL_VAL  0xffff

#define METHOD_ATTRIBUTE_MEMBER_ACCESS_MASK        0x0007
#define METHOD_ATTRIBUTE_COMPILER_CONTROLLED       0x0000
#define METHOD_ATTRIBUTE_PRIVATE                   0x0001
#define METHOD_ATTRIBUTE_FAM_AND_ASSEM             0x0002
#define METHOD_ATTRIBUTE_ASSEM                     0x0003
#define METHOD_ATTRIBUTE_FAMILY                    0x0004
#define METHOD_ATTRIBUTE_FAM_OR_ASSEM              0x0005
#define METHOD_ATTRIBUTE_PUBLIC                    0x0006

#define METHOD_ATTRIBUTE_STATIC                    0x0010
#define METHOD_ATTRIBUTE_FINAL                     0x0020
#define METHOD_ATTRIBUTE_VIRTUAL                   0x0040
#define METHOD_ATTRIBUTE_HIDE_BY_SIG               0x0080

#define METHOD_ATTRIBUTE_VTABLE_LAYOUT_MASK        0x0100
#define METHOD_ATTRIBUTE_REUSE_SLOT                0x0000
#define METHOD_ATTRIBUTE_NEW_SLOT                  0x0100

#define METHOD_ATTRIBUTE_STRICT                    0x0200
#define METHOD_ATTRIBUTE_ABSTRACT                  0x0400
#define METHOD_ATTRIBUTE_SPECIAL_NAME              0x0800

#define METHOD_ATTRIBUTE_PINVOKE_IMPL              0x2000
#define METHOD_ATTRIBUTE_UNMANAGED_EXPORT          0x0008

/*
 * For runtime use only
 */
#define METHOD_ATTRIBUTE_RESERVED_MASK             0xd000
#define METHOD_ATTRIBUTE_RT_SPECIAL_NAME           0x1000
#define METHOD_ATTRIBUTE_HAS_SECURITY              0x4000
#define METHOD_ATTRIBUTE_REQUIRE_SEC_OBJECT        0x8000

/*
* Type Attributes (21.1.13).
*/
#define TYPE_ATTRIBUTE_VISIBILITY_MASK       0x00000007
#define TYPE_ATTRIBUTE_NOT_PUBLIC            0x00000000
#define TYPE_ATTRIBUTE_PUBLIC                0x00000001
#define TYPE_ATTRIBUTE_NESTED_PUBLIC         0x00000002
#define TYPE_ATTRIBUTE_NESTED_PRIVATE        0x00000003
#define TYPE_ATTRIBUTE_NESTED_FAMILY         0x00000004
#define TYPE_ATTRIBUTE_NESTED_ASSEMBLY       0x00000005
#define TYPE_ATTRIBUTE_NESTED_FAM_AND_ASSEM  0x00000006
#define TYPE_ATTRIBUTE_NESTED_FAM_OR_ASSEM   0x00000007

#define TYPE_ATTRIBUTE_LAYOUT_MASK           0x00000018
#define TYPE_ATTRIBUTE_AUTO_LAYOUT           0x00000000
#define TYPE_ATTRIBUTE_SEQUENTIAL_LAYOUT     0x00000008
#define TYPE_ATTRIBUTE_EXPLICIT_LAYOUT       0x00000010

#define TYPE_ATTRIBUTE_CLASS_SEMANTIC_MASK   0x00000020
#define TYPE_ATTRIBUTE_CLASS                 0x00000000
#define TYPE_ATTRIBUTE_INTERFACE             0x00000020

#define TYPE_ATTRIBUTE_ABSTRACT              0x00000080
#define TYPE_ATTRIBUTE_SEALED                0x00000100
#define TYPE_ATTRIBUTE_SPECIAL_NAME          0x00000400

#define TYPE_ATTRIBUTE_IMPORT                0x00001000
#define TYPE_ATTRIBUTE_SERIALIZABLE          0x00002000

#define TYPE_ATTRIBUTE_STRING_FORMAT_MASK    0x00030000
#define TYPE_ATTRIBUTE_ANSI_CLASS            0x00000000
#define TYPE_ATTRIBUTE_UNICODE_CLASS         0x00010000
#define TYPE_ATTRIBUTE_AUTO_CLASS            0x00020000

#define TYPE_ATTRIBUTE_BEFORE_FIELD_INIT     0x00100000
#define TYPE_ATTRIBUTE_FORWARDER             0x00200000

#define TYPE_ATTRIBUTE_RESERVED_MASK         0x00040800
#define TYPE_ATTRIBUTE_RT_SPECIAL_NAME       0x00000800
#define TYPE_ATTRIBUTE_HAS_SECURITY          0x00040000

/*
* Flags for Params (22.1.12)
*/
#define PARAM_ATTRIBUTE_IN                 0x0001
#define PARAM_ATTRIBUTE_OUT                0x0002
#define PARAM_ATTRIBUTE_OPTIONAL           0x0010
#define PARAM_ATTRIBUTE_RESERVED_MASK      0xf000
#define PARAM_ATTRIBUTE_HAS_DEFAULT        0x1000
#define PARAM_ATTRIBUTE_HAS_FIELD_MARSHAL  0x2000
#define PARAM_ATTRIBUTE_UNUSED             0xcfe0

// Flags for Generic Parameters (II.23.1.7)
#define IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_NON_VARIANT                           0x00
#define IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_COVARIANT                             0x01
#define IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_CONTRAVARIANT                         0x02
#define IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_VARIANCE_MASK                         0x03
#define IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_REFERENCE_TYPE_CONSTRAINT             0x04
#define IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_NOT_NULLABLE_VALUE_TYPE_CONSTRAINT    0x08
#define IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_DEFAULT_CONSTRUCTOR_CONSTRAINT        0x10
#define IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_SPECIAL_CONSTRAINT_MASK               0x1C

/**
 * 21.5 AssemblyRefs
 */
#define ASSEMBLYREF_FULL_PUBLIC_KEY_FLAG      0x00000001
#define ASSEMBLYREF_RETARGETABLE_FLAG         0x00000100
#define ASSEMBLYREF_ENABLEJITCOMPILE_TRACKING_FLAG 0x00008000
#define ASSEMBLYREF_DISABLEJITCOMPILE_OPTIMIZER_FLAG 0x00004000

namespace cs {
    typedef void Il2CppDomain;
    typedef void Il2CppClass;
    typedef void Il2CppType;
    typedef void Il2CppObject;
    typedef void Il2CppAssembly;
    typedef void Il2CppImage;
    typedef void FieldInfo;
    typedef void MethodInfo;

    template<typename T>
    class function_ptr {
    public:
        function_ptr() = default;
        explicit function_ptr(void* address) : _fn(reinterpret_cast<T>(address)) {}

        inline bool valid() const { return _fn != nullptr; }
        inline operator bool() const { return valid(); }

        T get() const { return _fn; }

    private:
        T _fn = nullptr;
    };

    class il2cpp_functions {
    public:
        explicit il2cpp_functions();

        // Function pointers
        function_ptr<void*(*)(void*)> assembly_get_image;
        function_ptr<void*(*)(void*, void**)> class_get_fields;
        function_ptr<MethodInfo*(*)(void*, void**)> class_get_methods;
        function_ptr<const char*(*)(void*)> class_get_name;
        function_ptr<const char*(*)(void*)> class_get_namespace;
        function_ptr<void*(*)(void*)> class_get_parent;
        function_ptr<bool(*)(void*)> class_is_valuetype;
        function_ptr<int32_t(*)(void*)> class_get_flags;
        function_ptr<void*(*)(void*)> class_from_type;
        function_ptr<bool(*)(void*)> class_is_enum;

        function_ptr<void*(*)()> domain_get;
        function_ptr<void**(*)(void*, const size_t*)> domain_get_assemblies;

        function_ptr<int32_t(*)(void*)> field_get_flags;
        function_ptr<const char*(*)(void*)> field_get_name;
        function_ptr<size_t(*)(void*)> field_get_offset;
        function_ptr<void*(*)(void*)> field_get_type;

        function_ptr<void*(*)(const MethodInfo*)> method_get_return_type;
        function_ptr<const char*(*)(const MethodInfo*)> method_get_name;
        function_ptr<uint32_t(*)(const MethodInfo*)> method_get_param_count;
        function_ptr<void*(*)(const MethodInfo*, uint32_t)> method_get_param;

        function_ptr<const char*(*)(void*)> type_get_name;
        function_ptr<bool(*)(void*)> type_is_byref;
        function_ptr<uint32_t(*)(void*)> type_get_attrs;

        function_ptr<const char*(*)(void*)> image_get_name;
        function_ptr<size_t(*)(void*)> image_get_class_count;
        function_ptr<void*(*)(void*, size_t)> image_get_class;

        // Check if function is valid
        bool is_valid() const;

        void *il2cpp_class_get_type(void *arg);

        uintptr_t il2cpp_method_get_relative_pointer(void *arg);

        // Wrappers for easier calling
        void* il2cpp_assembly_get_image(void* arg);
        void* il2cpp_class_get_fields(void* arg, void** arg2);
        MethodInfo* il2cpp_class_get_methods(void* arg, void** arg2);
        const char* il2cpp_class_get_name(void* arg);
        const char* il2cpp_class_get_namespace(void* arg);
        void* il2cpp_class_get_parent(void* arg);
        bool il2cpp_class_is_valuetype(void* arg);
        int32_t il2cpp_class_get_flags(void* arg);
        void* il2cpp_class_from_type(void* arg);
        bool il2cpp_class_is_enum(void* arg);

        void* il2cpp_domain_get();
        void** il2cpp_domain_get_assemblies(void* arg, const size_t* size);

        int32_t il2cpp_field_get_flags(void* arg);
        const char* il2cpp_field_get_name(void* arg);
        size_t il2cpp_field_get_offset(void* arg);
        void* il2cpp_field_get_type(void* arg);

        void* il2cpp_method_get_return_type(const MethodInfo* arg);
        const char* il2cpp_method_get_name(const MethodInfo* arg);
        uint32_t il2cpp_method_get_param_count(const MethodInfo* arg);
        void* il2cpp_method_get_param(const MethodInfo* arg, uint32_t index);

        const char* il2cpp_type_get_name(void* arg);
        bool il2cpp_type_is_byref(void* arg);
        uint32_t il2cpp_type_get_attrs(void* arg);

        const char* il2cpp_image_get_name(void* arg);
        size_t il2cpp_image_get_class_count(void* arg);
        void* il2cpp_image_get_class(void* arg, size_t index);

    private:
        void** _table;

        template<typename T>
        function_ptr<T> resolve(size_t index);
    };

} // namespace cs

#endif // CS_IL2CPP_FUNCTIONS_H
