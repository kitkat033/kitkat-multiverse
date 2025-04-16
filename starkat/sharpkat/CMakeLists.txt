cmake_minimum_required(VERSION 3.30)
project(sharpkat)

set(CMAKE_CXX_STANDARD 20)

add_library(sharpkat SHARED library.cpp
        entry.cpp
        entry.h
        util/logger.cpp
        util/logger.h
        util/mem.cpp
        util/mem.h
        api/il2cpp_functions.cpp
        api/il2cpp_functions.h
        dumper/domain.cpp
        dumper/domain.h
        dumper/assembly.cpp
        dumper/assembly.h
        dumper/class.cpp
        dumper/class.h
        dumper/fields.cpp
        dumper/fields.h
        dumper/methods.cpp
        dumper/methods.h
        dumper/methods.cpp
        dumper/methods.h
)
