#include <catch2/catch_test_macros.hpp>

template<typename T>
T abs(T val);

TEST_CASE("", "[example]")
{
    REQUIRE(abs<long>(0) == 0);
    REQUIRE(abs(0) == 0);
    REQUIRE(abs<double>(0.0) == 0.0);
}

double almost_equal(double value, double expected, double epsylon = 0.00001)
{
    if (value >= expected - epsylon && value <= expected + epsylon)
    {
        return true;
    }
    return false;
}

TEST_CASE("one", "[example]")
{
    REQUIRE(abs<long>(1) == 1);
    REQUIRE(abs(1) == 1);
    REQUIRE(almost_equal(abs<double>(1.0), 1.0));
    auto value = 5 * 4 / 2.0;
    abs<typeof(value)>(8);

    typedef char Znak;
    char znakova_premenna;
    typedef typeof(znakova_premenna) ZnakAlias;
    using ZnakAlias = typeof(znakova_premenna);
    using str = std::string;
}

