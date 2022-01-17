cmake_minimum_required(VERSION 3.16)

enable_testing()
add_subdirectory(libMstp)

add_executable(
  ${PROJECT_NAME}
  main.cpp
)

target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE
  libMstp
)
