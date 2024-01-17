#include <catch2/catch_test_macros.hpp>

#include "../src/compute_residual.hpp"

#ifdef USING_MPI
#include <mpi.h>
#endif

TEST_CASE("Test compute residual implementation") {
#ifdef USING_MPI
    char **argv = {};
    int argc = 0;
    MPI_Init(&argc, &argv);
    int size, rank;  // Number of MPI processes, My process ID
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
#endif

    int width = 3;
    double lhs[] = {1.0, 2.0, 3.0};
    double rhs[] = {3.0, 2.0, 1.0};
    double result;
    compute_residual(width, lhs, rhs, &result);
    REQUIRE(result == 2.0);
}
