cmake_minimum_required(VERSION 4.0)
project(CPlusPlusThings)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# MSVC中文乱码警告消除（可选推荐）
if(MSVC)
    add_compile_options(/utf-8)
endif()

add_subdirectory(basic_content/const/class_const/c++11_example)
add_subdirectory(basic_content/const/class_const/first_example)
add_subdirectory(basic_content/c_poly)
add_subdirectory(basic_content/abstract)
