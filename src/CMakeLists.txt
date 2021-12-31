add_executable(${PROJECT_NAME}
  main.cpp
  PatternGenerator.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)
