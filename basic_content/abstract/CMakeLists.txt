cmake_minimum_required(VERSION 4.0)
project(AbstractDemo)
set(CMAKE_CXX_STANDARD 11)
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-finput-charset=UTF-8 -fexec-charset=GBK)
endif()
add_executable(AbstractMain abstract.cpp abstract_base.h)
#derived_full.cpp interesting_facts1.cpp interesting_facts2.cpp interesting_facts3.cpp interesting_facts4.cpp interesting_facts5.cpp pure_virtual.cpp

