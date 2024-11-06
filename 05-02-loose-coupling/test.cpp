#define CATCH_CONFIG_MAIN

#include <catch2/catch_test_macros.hpp>
#include "classes.h"

TEST_CASE("Zero input", "[zombies]")
{
    auto csv = new CSVParser();
    REQUIRE_THROWS(csv->get_value(0, 0));
    REQUIRE_THROWS(csv->get_value(0, 1));
    REQUIRE_THROWS(csv->get_value(1, 1));
    REQUIRE_THROWS(csv->get_value(1, 0));
    delete csv;

    csv = new CSVParser();
    csv->parse_line("");
    REQUIRE_THROWS(csv->get_value(0, 0));
    REQUIRE_THROWS(csv->get_value(0, 1));
    REQUIRE_THROWS(csv->get_value(1, 1));
    REQUIRE_THROWS(csv->get_value(1, 0));
}

TEST_CASE("One line", "[zombies]")
{
    auto csv = new CSVParser();
    csv->parse_line("1");

    REQUIRE_NOTHROW(csv->get_value(0, 0));
    REQUIRE(csv->get_value(0, 0) == 1);
}


TEST_CASE("Multiple lines", "[zombies]")
{
    auto csv = new CSVParser();
    csv->parse_line("1\t2");

    REQUIRE(csv->get_value(0, 0) == 1);
    REQUIRE(csv->get_value(0, 1) == 2);
}

TEST_CASE("Boundary conditions", "[zombies]")
{
    auto csv = new CSVParser();
    csv->parse_line("1\t2\t3\t4\t5\t6\t7");

    REQUIRE(csv->get_value(0, 5) == 6);
    REQUIRE(csv->get_value(0, 6) == 7);
    REQUIRE_THROWS(csv->get_value(0, 7));
}

TEST_CASE("Exceptional behavior", "[zombies]")
{
    auto csv = new CSVParser();
    REQUIRE_THROWS(csv->parse_line("A!\t2\t3\t4"));

    REQUIRE_THROWS(csv->get_value(0, 0));

    csv->parse_line("1\t2\t3\t4\t5\t6\t7");

    REQUIRE(csv->get_value(0, 0) == 1);
}

