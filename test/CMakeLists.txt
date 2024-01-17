Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.4.0 # or a later release
)
FetchContent_MakeAvailable(Catch2)

set(TEST_SOURCE_FILES
        test_generate_matrix.cpp test_ddot.cpp test_waxpby.cpp
        test_compute_residual.cpp test_sparsemv.cpp test_HPCCG.cpp
)

add_executable(Catch2Tests ${TEST_SOURCE_FILES})
target_link_libraries(Catch2Tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(Catch2Tests PRIVATE HPCCG)

# If the environment variable is set, build with MPI
if ($ENV{USE_MPI})
    find_package(MPI REQUIRED)
    message(STATUS "Run: ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} ${MPIEXEC_MAX_NUMPROCS} ${MPIEXEC_PREFLAGS} EXECUTABLE ${MPIEXEC_POSTFLAGS} ARGS")
    target_link_libraries(Catch2Tests PUBLIC MPI::MPI_CXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSING_MPI")
    message(STATUS "Updated CXX flags: ${CMAKE_CXX_FLAGS}")
endif()


list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
include(CTest)
include(Catch)
catch_discover_tests(Catch2Tests)
