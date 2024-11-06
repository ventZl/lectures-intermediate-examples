#include <typeinfo>
#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>

class Serializer {
public:
    Serializer(std::ostream & output): m_output{output} {}

    template<typename T>
    void push(const T value)
    {
        auto & val_type = typeid(T);
        size_t type_hash = val_type.hash_code();

        m_output.write(reinterpret_cast<char *>(&type_hash), sizeof(type_hash));
        m_output.write(reinterpret_cast<const char *>(&value), sizeof(T));
    }

protected:
    std::ostream & m_output;
};

class Deserializer {
public:
    Deserializer(std::istream & input): m_input{input} {}

    template<typename T>
    void pop(T & output)
    {

        auto & val_type = typeid(T);
        size_t type_hash = val_type.hash_code();

        size_t data_hash = 0;
        m_input.read(reinterpret_cast<char *>(&data_hash), sizeof(data_hash));

        if (data_hash != type_hash)
        {
            throw std::runtime_error("Serialized data type mismatch");
        }

        m_input.read(reinterpret_cast<char *>(&output), sizeof(T));
    }


protected:
    std::istream & m_input;
};

int main(int argc, char ** argv)
{
    std::fstream file;
    file.open("serialized.bin", std::fstream::out | std::fstream::trunc);
    {
        Serializer one_value(file);
        uint32_t data = 42;
        one_value.push(data);
        file.close();
    }

    file.open("serialized.bin", std::fstream::in);
    {
        Deserializer one_value(file);
        uint32_t data;
        one_value.pop(data);
        std::cout << "Value at offset 0 is: " << data << std::endl;
    }
    file.close();
}
