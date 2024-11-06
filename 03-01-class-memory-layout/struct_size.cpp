#include <iostream>

struct T {
public:
    T(int value): m_value{value} {}
    int value() const { return m_value; }
    void value(int value) { replace(value); }
protected:
    void replace(int value) { if (value != m_value) { m_value = value; } }
private:
    int m_value;
};

int main(int /* argc */, char ** /* argv */)
{
    std::cout << "sizeof(T) = " << sizeof(T) << std::endl;
    return 0;
}
