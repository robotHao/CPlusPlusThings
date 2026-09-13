cmake_minimum_required(VERSION 4.0)
project(AbstractDemo)
set(CMAKE_CXX_STANDARD 11)
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-finput-charset=UTF-8 -fexec-charset=GBK)
endif()
add_executable(AbstractMain abstract.cpp abstract_base.h) #相当于创建一个可执行文件，且一个对象中只可能有一个main函数，若包含多个main函数就需要重新创建一个可执行文件
add_executable(PureMain pure_virtual.cpp)
#derived_full.cpp interesting_facts1.cpp interesting_facts2.cpp interesting_facts3.cpp interesting_facts4.cpp interesting_facts5.cpp

