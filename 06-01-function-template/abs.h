#pragma once


template<typename T>
T abs(T val) {
    if (val < 0) return -val;
    return val;
}
