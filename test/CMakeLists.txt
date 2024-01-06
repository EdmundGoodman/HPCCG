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

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
include(CTest)
include(Catch)
catch_discover_tests(Catch2Tests)
