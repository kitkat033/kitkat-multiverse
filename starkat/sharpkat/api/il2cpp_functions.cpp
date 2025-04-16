#include "il2cpp_functions.h"

#include "../entry.h"

namespace cs {

    template<typename T>
    function_ptr<T> il2cpp_functions::resolve(size_t index) {
        void* addr = const_cast<void*>(_table[index]);
        return addr ? function_ptr<T>(addr) : function_ptr<T>();
    }

    il2cpp_functions::il2cpp_functions() {
        _table = reinterpret_cast<void**>(settings.il2cpp_init);

        assembly_get_image = resolve<void*(*)(void*)>(22);
        class_get_methods = resolve<MethodInfo*(*)(void*, void**)>(35);
        class_get_name = resolve<const char*(*)(void*)>(37);
        class_get_namespace = resolve<const char*(*)(void*)>(39);
        domain_get = resolve<void*(*)()>(63);
        domain_get_assemblies = resolve<void**(*)(void*, const size_t*)>(65);
        method_get_name = resolve<const char*(*)(const MethodInfo*)>(117);
        image_get_class_count = resolve<size_t(*)(void*)>(169);
        image_get_class = resolve<void*(*)(void*, size_t)>(170);

        class_get_fields = resolve<void*(*)(void*, void**)>(31);
        class_get_parent = resolve<void*(*)(void*)>(40);
        class_is_valuetype = resolve<bool(*)(void*)>(43);
        class_get_flags = resolve<int32_t(*)(void*)>(45);
        class_from_type = resolve<void*(*)(void*)>(49);
        class_is_enum = resolve<bool(*)(void*)>(53);
        field_get_flags = resolve<int32_t(*)(void*)>(72);
        field_get_name = resolve<const char*(*)(void*)>(73);
        field_get_offset = resolve<size_t(*)(void*)>(75);
        field_get_type = resolve<void*(*)(void*)>(76);
        method_get_return_type = resolve<void*(*)(const MethodInfo*)>(116);
        method_get_param_count = resolve<uint32_t(*)(const MethodInfo*)>(123);
        method_get_param = resolve<void*(*)(const MethodInfo*, uint32_t)>(124);
        type_get_name = resolve<const char*(*)(void*)>(161);
        type_is_byref = resolve<bool(*)(void*)>(162);
        type_get_attrs = resolve<uint32_t(*)(void*)>(163);
        image_get_name = resolve<const char*(*)(void*)>(168);
    }

    bool il2cpp_functions::is_valid() const {
        return assembly_get_image.valid() && class_get_methods.valid();
    }

    void* il2cpp_functions::il2cpp_class_get_type(void* arg) {
        return (void*)((uintptr_t)arg + settings.class_byval);
    }

    uintptr_t il2cpp_functions::il2cpp_method_get_relative_pointer(void* arg) {
        auto ptr = *reinterpret_cast<uintptr_t*>((uintptr_t)arg + 0x08);

        if (ptr == 0) {
            return 0;
        }

        return ptr - settings.ga;
    }

    // Wrappers for safe function calls
    void* il2cpp_functions::il2cpp_assembly_get_image(void* arg) {
        return assembly_get_image.valid() ? assembly_get_image.get()(arg) : nullptr;
    }

    void* il2cpp_functions::il2cpp_class_get_fields(void* arg, void** arg2) {
        return class_get_fields.valid() ? class_get_fields.get()(arg, arg2) : nullptr;
    }

    MethodInfo* il2cpp_functions::il2cpp_class_get_methods(void* arg, void** arg2) {
        return class_get_methods.valid() ? class_get_methods.get()(arg, arg2) : nullptr;
    }

    const char* il2cpp_functions::il2cpp_class_get_name(void* arg) {
        return class_get_name.valid() ? class_get_name.get()(arg) : nullptr;
    }

    const char* il2cpp_functions::il2cpp_class_get_namespace(void* arg) {
        return class_get_namespace.valid() ? class_get_namespace.get()(arg) : nullptr;
    }

    void* il2cpp_functions::il2cpp_class_get_parent(void* arg) {
        return class_get_parent.valid() ? class_get_parent.get()(arg) : nullptr;
    }

    bool il2cpp_functions::il2cpp_class_is_valuetype(void* arg) {
        return class_is_valuetype.valid() && class_is_valuetype.get()(arg);
    }

    int32_t il2cpp_functions::il2cpp_class_get_flags(void* arg) {
        return class_get_flags.valid() ? class_get_flags.get()(arg) : 0;
    }

    void* il2cpp_functions::il2cpp_class_from_type(void* arg) {
        return class_from_type.valid() ? class_from_type.get()(arg) : nullptr;
    }

    bool il2cpp_functions::il2cpp_class_is_enum(void* arg) {
        return class_is_enum.valid() && class_is_enum.get()(arg);
    }

    void* il2cpp_functions::il2cpp_domain_get() {
        return domain_get.valid() ? domain_get.get()() : nullptr;
    }

    void** il2cpp_functions::il2cpp_domain_get_assemblies(void* arg, const size_t* size) {
        return domain_get_assemblies.valid() ? domain_get_assemblies.get()(arg, size) : nullptr;
    }

    int32_t il2cpp_functions::il2cpp_field_get_flags(void* arg) {
        return field_get_flags.valid() ? field_get_flags.get()(arg) : 0;
    }

    const char* il2cpp_functions::il2cpp_field_get_name(void* arg) {
        return field_get_name.valid() ? field_get_name.get()(arg) : nullptr;
    }

    size_t il2cpp_functions::il2cpp_field_get_offset(void* arg) {
        return field_get_offset.valid() ? field_get_offset.get()(arg) : 0;
    }

    void* il2cpp_functions::il2cpp_field_get_type(void* arg) {
        return field_get_type.valid() ? field_get_type.get()(arg) : nullptr;
    }

    void* il2cpp_functions::il2cpp_method_get_return_type(const MethodInfo* arg) {
        return method_get_return_type.valid() ? method_get_return_type.get()(arg) : nullptr;
    }

    const char* il2cpp_functions::il2cpp_method_get_name(const MethodInfo* arg) {
        return method_get_name.valid() ? method_get_name.get()(arg) : nullptr;
    }

    uint32_t il2cpp_functions::il2cpp_method_get_param_count(const MethodInfo* arg) {
        return method_get_param_count.valid() ? method_get_param_count.get()(arg) : 0;
    }

    void* il2cpp_functions::il2cpp_method_get_param(const MethodInfo* arg, uint32_t index) {
        return method_get_param.valid() ? method_get_param.get()(arg, index) : nullptr;
    }

    const char* il2cpp_functions::il2cpp_type_get_name(void* arg) {
        return type_get_name.valid() ? type_get_name.get()(arg) : nullptr;
    }

    bool il2cpp_functions::il2cpp_type_is_byref(void* arg) {
        return type_is_byref.valid() && type_is_byref.get()(arg);
    }

    uint32_t il2cpp_functions::il2cpp_type_get_attrs(void* arg) {
        return type_get_attrs.valid() ? type_get_attrs.get()(arg) : 0;
    }

    const char* il2cpp_functions::il2cpp_image_get_name(void* arg) {
        return image_get_name.valid() ? image_get_name.get()(arg) : nullptr;
    }

    size_t il2cpp_functions::il2cpp_image_get_class_count(void* arg) {
        return image_get_class_count.valid() ? image_get_class_count.get()(arg) : 0;
    }

    void* il2cpp_functions::il2cpp_image_get_class(void* arg, size_t index) {
        return image_get_class.valid() ? image_get_class.get()(arg, index) : nullptr;
    }

} // namespace cs
