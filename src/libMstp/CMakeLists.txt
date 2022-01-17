cmake_minimum_required(VERSION 3.16)

# libMstp
project(libMstp VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)

add_library(
  ${PROJECT_NAME}
  STATIC
  PatternGenerator.cpp
)

target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE
  Threads::Threads
)

# Google Test
string(CONCAT TEST_PROJECT_NAME ${PROJECT_NAME} "Test")

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG 4e9fe30884414b58d219d0170d39cbad96e5758a
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  ${TEST_PROJECT_NAME}
  PatternGenerator.test.cpp
)

target_link_libraries(
  ${TEST_PROJECT_NAME}
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(${TEST_PROJECT_NAME})
