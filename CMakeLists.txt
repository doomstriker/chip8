cmake_minimum_required(VERSION 3.0.0)
project(Chip8 VERSION 0.1.0)

include(CTest)
enable_testing()
target_include_directories(Chip8 PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
add_executable(Chip8 main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
