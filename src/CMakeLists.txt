# Ensure the exectuables are outputted to the project base directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}")

# Compile the source files
set(SOURCE_FILES
        generate_matrix.cpp read_HPC_row.cpp compute_residual.cpp mytimer.cpp
        dump_matlab_matrix.cpp HPC_sparsemv.cpp HPCCG.cpp waxpby.cpp ddot.cpp
        make_local_matrix.cpp exchange_externals.cpp YAML_Element.cpp YAML_Doc.cpp
)
add_library (HPCCG ${SOURCE_FILES})

# If the environment variable is set, build with OpenMP
if ($ENV{USE_OMP})
    find_package(OpenMP)
    if(OpenMP_CXX_FOUND)
        target_link_libraries(HPCCG PUBLIC OpenMP::OpenMP_CXX)
    endif()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSING_OMP")
    message(STATUS "Updated CXX flags: ${CMAKE_CXX_FLAGS}")
endif()

# If the environment variable is set, build with MPI
if ($ENV{USE_MPI})
    find_package(MPI REQUIRED)
    message(STATUS "Run: ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} ${MPIEXEC_MAX_NUMPROCS} ${MPIEXEC_PREFLAGS} EXECUTABLE ${MPIEXEC_POSTFLAGS} ARGS")
    target_link_libraries(HPCCG PUBLIC MPI::MPI_CXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSING_MPI")
    message(STATUS "Updated CXX flags: ${CMAKE_CXX_FLAGS}")
endif()


add_executable (test_HPCCG main.cpp)
target_link_libraries (test_HPCCG HPCCG)
