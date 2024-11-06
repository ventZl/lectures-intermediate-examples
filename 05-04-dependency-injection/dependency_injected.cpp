#include "classes_injected.h"
#include <catch2/catch_test_macros.hpp>

class LineStreamerMock: public LineStreamer {
public:
    LineStreamerMock(std::vector<std::string> input_data): m_input{input_data} {}

    std::string get_line() {
        if (m_cursor < m_input.size())
        {
            return m_input[m_cursor++];
        }

        return "";
    }

protected:
    std::vector<std::string> m_input;
    unsigned m_cursor {0};
};

TEST_CASE("Zero input", "[csv_parser]")
{
    // empty input
    LineStreamerMock mock({});
    CSVParser csv(mock);
    csv.parse();

    REQUIRE_THROWS(csv.get_value(0, 0));
    REQUIRE_THROWS(csv.get_value(0, 1));
    REQUIRE_THROWS(csv.get_value(1, 1));
    REQUIRE_THROWS(csv.get_value(1, 0));
}

TEST_CASE("Empty input", "[csv_parser]")
{
    LineStreamerMock mock({""});
    CSVParser csv(mock);
    csv.parse();

    REQUIRE_THROWS(csv.get_value(0, 0));
    REQUIRE_THROWS(csv.get_value(0, 1));
    REQUIRE_THROWS(csv.get_value(1, 1));
    REQUIRE_THROWS(csv.get_value(1, 0));
}

TEST_CASE("One line", "[csv_parser]")
{
    LineStreamerMock mock({"1"});
    CSVParser csv(mock);
    csv.parse();


    REQUIRE_NOTHROW(csv.get_value(0, 0));
    REQUIRE(csv.get_value(0, 0) == 1);
}


TEST_CASE("Multiple lines", "[csv_parser]")
{
    LineStreamerMock mock({"1\t2"});
    CSVParser csv(mock);
    csv.parse();


    REQUIRE(csv.get_value(0, 0) == 1);
    REQUIRE(csv.get_value(0, 1) == 2);
}

TEST_CASE("Boundary conditions", "[csv_parser]")
{
    LineStreamerMock mock({"1\t2\t3\t4\t5\t6\t7"});
    CSVParser csv(mock);
    csv.parse();


    REQUIRE(csv.get_value(0, 5) == 6);
    REQUIRE(csv.get_value(0, 6) == 7);
    REQUIRE_THROWS(csv.get_value(0, 7));
}

TEST_CASE("Exceptional behavior", "[csv_parser]")
{
    LineStreamerMock mock({"A!\t2\t3\t4"});
    CSVParser csv(mock);
    REQUIRE_THROWS(csv.parse());

    REQUIRE_THROWS(csv.get_value(0, 0));
}

