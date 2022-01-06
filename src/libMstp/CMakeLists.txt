cmake_minimum_required(VERSION 3.16)

project(libMstp VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)

add_library(${PROJECT_NAME} STATIC PatternGenerator.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)
