#include <catch2/catch_test_macros.hpp>
#include "array.h"

TEST_CASE("", "[array]")
{
    Array<char, 5> name;
    name[0] = 5;
    REQUIRE(name[0] == 5);
}
