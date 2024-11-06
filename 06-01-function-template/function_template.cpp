#include <typeinfo>
#include <iostream>

template<typename T>
T abs(T val) {
    if (val < 0) return -val;
    return val;
}

int main(int argc, char ** argv)
{
    auto val = abs<float>(5.0f);
    std::cout << "val type is " << typeid(val).name() << std::endl;
}
