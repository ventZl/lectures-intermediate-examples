#include <typeinfo>
#include <iostream>
#include <string>

double abs(double val) {
    if (val < 0) return -val;
    return val;
}

float abs(float val) {
    if (val < 0) return -val;
    return val;
}

long abs(long val) {
    std::cout << "Non templatized" << std::endl;
    if (val < 0) return -val;
    return val;
}

short abs(short val) {
    if (val < 0) return -val;
    return val;
}

int abs(int val) {
    if (val < 0) return -val;
    return val;
}

char abs(char val) {
    if (val < 0) return -val;
    return val;
}

template<typename T>
T abs(T val) {
    if (val < 0) return -val;
    return val;
}

template<typename T>
T random_number()
{
    return /* ... */;
}

int main(int argc, char ** argv)
{
    long input = 5;
    auto val = abs<>(input);
    std::cout << "val type is " << typeid(val).name() << std::endl;
}
