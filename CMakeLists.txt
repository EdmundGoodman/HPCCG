cmake_minimum_required(VERSION 3.26)
project(
        HPCCG
        VERSION 1.1.0
        DESCRIPTION "High Performance Computing Conjugate Gradients: The original Mantevo miniapp."
        LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 17)

# Specify C++ compiler flags (if any)
set(CMAKE_CXX_FLAGS "-O3 $ENV{EXTRA_COMPILER_FLAGS}")
message(STATUS "CXX flags: ${CMAKE_CXX_FLAGS}")

# Build the source and test directories
add_subdirectory(src)
add_subdirectory(test)
enable_testing()
