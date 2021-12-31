cmake_minimum_required(VERSION 3.16)

project(MstpGeneratorLib VERSION 1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)
add_compile_options(-Wall -Wextra -Ofast)

add_subdirectory(src)
