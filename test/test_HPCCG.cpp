#include <catch2/catch_test_macros.hpp>

#include "../src/HPCCG.hpp"
#include "../src/HPC_Sparse_Matrix.hpp"
#include "../src/compute_residual.hpp"
#include "../src/generate_matrix.hpp"

#ifdef USING_MPI
#include <mpi.h>
#endif

TEST_CASE("Integration test HPCCG solver") {
#ifdef USING_MPI
    char **argv = {};
    int argc = 0;
    MPI_Init(&argc, &argv);
    int size, rank;  // Number of MPI processes, My process ID
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
#endif

    // Generate the sparse matrix for the test
    int nx = 5;
    int ny = 5;
    int nz = 5;
    HPC_Sparse_Matrix *A;
    double *x, *b, *xexact;
    generate_matrix(nx, ny, nz, &A, &x, &b, &xexact);

    // Configure the solver
    int niters = 0;
    double normr = 0.0;
    int max_iter = 150;
    double tolerance = 0.0;
    double times[7];

    SECTION("Solver runs without error") {
        int ierr = HPCCG(A, b, x, max_iter, tolerance, niters, normr, times);
        REQUIRE(ierr == 0);
    }

    SECTION("Solver result is within expected range") {
        double expected = 5e-40;
        REQUIRE(normr < expected);
    }

    SECTION("Solver iterations within expected range") { REQUIRE(niters < max_iter); }
}
