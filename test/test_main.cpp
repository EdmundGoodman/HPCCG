#include <catch2/catch_test_macros.hpp>
#include "../src/ddot.hpp"

TEST_CASE("Quick check", "[ddot]" ) {
//    REQUIRE( 2.0 == 2.0 );
    int n = 1;
    double x[] = {2.0};
    double y[] = {2.0};
    double result[] = {0.0};
    double time_allreduce[] = {};
    double expected[] = {x[0]*y[0]};
    ddot(n, x, y, result, *time_allreduce);
    REQUIRE(result[0] == expected[0]);
}
