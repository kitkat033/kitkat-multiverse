#include "assembly.h"
#include "class.h"
#include "fields.h"
#include "methods.h"
#include "../util/logger.h"

namespace cs {
    namespace dump {
        void dump_assembly(il2cpp_functions *funcs, Il2CppAssembly *assembly, int assemblyIndex,
                           std::ofstream *stream) {
            Il2CppImage *image = funcs->il2cpp_assembly_get_image(assembly);
            size_t classCount = funcs->il2cpp_image_get_class_count(image);

            *stream << "// -~* starting assembly #" << assemblyIndex << " *~-\n";
            *stream << "// * name:" << funcs->il2cpp_image_get_name(image);
            *stream << "\n// * class_count:" << classCount;
            *stream << "\n// -~* starting assembly #" << assemblyIndex << " *~-\n\n";

            for (int i = 0; i < classCount; i++) {
                Il2CppClass *klass = funcs->il2cpp_image_get_class(image, i);

                const char *fullName = funcs->il2cpp_type_get_name(funcs->il2cpp_class_get_type(klass));
                const char *dot = strrchr(fullName, '.');
                const char *name = dot ? dot + 1 : fullName;
                const char *namespaze = funcs->il2cpp_class_get_namespace(klass);

                *stream << "// TypeDefIndex: " << i << "\n"
                        << "// Namespace: "
                        << (namespaze[0] ? namespaze : "(none)") << "\n"
                        << "// FullName: "
                        << fullName << "\n"
                        << "// Assembly: "
                        << funcs->il2cpp_image_get_name(image)
                        << " (" << assemblyIndex << ")\n";

                get_class_modifiers(klass, funcs, stream);
                *stream << name;

                Il2CppClass *parent = funcs->il2cpp_class_get_parent(klass);

                if (parent != nullptr) {
                    const char *name1 = funcs->il2cpp_class_get_name(parent);
                    *stream << " : " << name1;
                }

                *stream << "\n{\n";
                *stream << "\t// Fields\n";
                dump_fields(funcs, klass, stream);

                *stream << "\n\t// Methods\n";
                dump_methods(funcs, klass, stream);
                *stream << "}\n\n";
            }
        }
    } // dump
} // cs
