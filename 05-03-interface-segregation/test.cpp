#include "motor_control.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Default state", "[example]")
{
    GPIO left_pin, right_pin;
    MotorControl controller(left_pin, right_pin);

    REQUIRE(controller.direction() == Direction::Stopped);
}

TEST_CASE("Rotate left", "[example]")
{
    GPIO left_pin, right_pin;
    MotorControl controller(left_pin, right_pin);
    controller.set_direction(Direction::Left);
    REQUIRE(controller.direction() == Direction::Left);
}

TEST_CASE("Rotate right", "[example]")
{
    GPIO left_pin, right_pin;
    MotorControl controller(left_pin, right_pin);
    controller.set_direction(Direction::Right);
    REQUIRE(controller.direction() == Direction::Right);
}
