#pragma once

enum class Direction {
    Left,
    Right,
    Stopped
};

class GPIO {
public:
    void set_state(bool active) { m_state = active; }
    bool state() const { return m_state; }
    /* */

protected:
    bool m_state {false};
};

class MotorControl {
public:
    MotorControl(GPIO left_pin, GPIO right_pin): m_left_pin{left_pin}, m_right_pin{right_pin} {}
    /* ... */

    void set_speed(unsigned speed) {}
    void set_direction(Direction dir) {
        if (dir == Direction::Left) {
            m_right_pin.set_state(false);
            m_left_pin.set_state(true);
        } else {
            m_left_pin.set_state(false);
            m_right_pin.set_state(true);
        }
    }

    void stop() {
        m_left_pin.set_state(false);
        m_right_pin.set_state(false);
    }

    void set_left_gpio(GPIO pin) {
        m_left_pin = pin;
    }

    void set_right_gpio(GPIO pin) {
        m_right_pin = pin;
    }

    Direction direction() const {
        if (m_left_pin.state() && !m_right_pin.state())
        {
            return Direction::Left;
        }
        if (!m_left_pin.state() && m_right_pin.state())
        {
            return Direction::Right;
        }
        return Direction::Stopped;
    }

    /* ... */

protected:
    GPIO m_left_pin;
    GPIO m_right_pin;
};
