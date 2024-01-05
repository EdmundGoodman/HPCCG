cmake_minimum_required(VERSION 3.26)
project(
        HPCCG
        VERSION 1.1.0
        DESCRIPTION "High Performance Computing Conjugate Gradients: The original Mantevo miniapp."
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)


# 1) Build with MPI or not?
#    If you want to run the program with MPI, make sure USE_MPI is set
#    to -DUSING_MPI
set(USE_MPI "")
# set(USE_MPI "-DUSING_MPI")

# 2) MPI headers:
#    If you:
#    - Are building MPI mode (-DUSING_MPI is set above).
#    - Do not have the MPI headers installed in a default search directory and
#    - Are not using MPI compiler wrappers
#    Then specify the path to your MPI header file (include a -I)
set(MPI_INC "")
# set(MPI_INC "-I/usr/MPICH/SDK.gcc/include")

# 3) Specify C++ compiler optimization flags (if any)
#    Typically some reasonably high level of optimization should be used to
#    enhance performance.
set(CPP_OPT_FLAGS "-O3 -ftree-vectorize -ftree-vectorizer-verbose=2")

# 4) Build with OpenMP or not?
#    If you want to run the program with OpenMP, make sure USING_OMP is set
#    to -DUSING_OMP
set(USE_OMP "")
# set(USE_OMP "-DUSING_OMP")

# 5) OpenMP Compiler argument
#    GCC and Intel compilers require -fopenmp and -openmp, resp.  Other compilers may differ.
set(OMP_FLAGS "")
# set(OMP_FLAGS "-fopenmp")

# 6) System libraries: (May need to add -lg2c before -lm)
set(SYS_LIB "-lm")

#set(CMAKE_CXX_FLAGS "${CPP_OPT_FLAGS} ${OMP_FLAGS} ${USE_OMP} ${USE_MPI} ${MPI_INC} ${SYS_LIB}")
set(CMAKE_CXX_FLAGS "")


# Ensure the exectuables are outputted correctly
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}")



add_subdirectory(src)
