#pragma once

#include <typeinfo>
#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>

class Serializable {
public:
    virtual ~Serializable() {}

    virtual void on_serialize(std::ostream & output) = 0;
    virtual void on_deserialize(std::istream & input) = 0;

    template<typename T>
    static void push(T value, std::ostream & output)
    {
        auto & val_type = typeid(T);
        size_t type_hash = val_type.hash_code();

        output.write(reinterpret_cast<char *>(&type_hash), sizeof(type_hash));
        output.write(reinterpret_cast<const char *>(&value), sizeof(T));
    }

    template<typename T>
    static void pop(T & value, std::istream & input)
    {

        auto & val_type = typeid(T);
        size_t type_hash = val_type.hash_code();

        size_t data_hash = 0;
        input.read(reinterpret_cast<char *>(&data_hash), sizeof(data_hash));

        if (data_hash != type_hash)
        {
            throw std::runtime_error("Serialized data type mismatch");
        }

        input.read(reinterpret_cast<char *>(&value), sizeof(T));
    }
};

template<typename T>
void operator>>(T & object, std::ostream & output)
{
    object.on_serialize(output);
}

template<typename T>
void operator<<(T & object, std::istream & input)
{
    object.on_deserialize(input);
}

#include "specialization.h"
