#include <iostream>

class T {
public:
    T(int value): m_value{value} {}
    virtual int value() const { return m_value; }
    virtual void value(int value) { replace(value); }
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
