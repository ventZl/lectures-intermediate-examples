#include "abs.h"
#include <memory>
class Demo {
    int value = 42;
};

namespace std {
    template<typename T>
    unique_ptr(T *) -> unique_ptr<T>;
}

int main()
{
    double dbl_val = 5.0;
    float flt_val = 5.0f;
    long long_val = 5;
    short short_val = 5;

    auto dbl_abs = abs(dbl_val);
    auto flt_abs = abs(flt_val);
    auto long_abs = abs(long_val);
    auto short_abs = abs(short_val);

    auto ptr = std::unique_ptr(new Demo());
}
