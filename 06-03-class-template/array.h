#pragma once

#include <stdexcept>

template<typename T, int N>
struct Array {
    constexpr unsigned size() const { return N; }
    T& operator[](int n) { if (0 <= n && n < N) return data[n]; throw std::range_error("Index out of range"); }
    const T& operator[](int n) const { if (0 <= n && n < N) return data[n]; throw std::range_error("Index out of range"); }

    T data[N];
};
