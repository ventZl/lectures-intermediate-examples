#include <typeinfo>
#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>

class Serializer {
public:
    Serializer(std::ostream & output): m_output{output} {}

protected:
    std::ostream & m_output;
};

class Deserializer {
public:
    Deserializer(std::istream & input): m_input{input} {}

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
