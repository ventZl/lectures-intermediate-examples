#pragma once

template<typename T>
class unique_ptr {
public:
    unique_ptr(): m_ptr{nullptr} {}
    unique_ptr(T * ptr): m_ptr{ptr} {}

    unique_ptr(const unique_ptr<T> & ptr) = delete;
    unique_ptr & operator=(const unique_ptr<T> & ptr) = delete;

    unique_ptr & operator=(const unique_ptr<T> && ptr)
    {
        m_ptr = ptr.m_ptr;
        ptr.m_ptr = nullptr;
    }

protected:
    T * m_ptr;
};
