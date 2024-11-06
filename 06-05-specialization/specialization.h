#pragma once

template<>
void operator>> <int>(int & value, std::ostream & output)
{
    Serializable::push(value, output);
}

template<>
void operator>> <long int>(long int & value, std::ostream & output)
{
    Serializable::push(value, output);
}

template<>
void operator>> <unsigned long int>(unsigned long int & value, std::ostream & output)
{
    Serializable::push(value, output);
}


template<>
void operator<< <int>(int & value, std::istream & input)
{
    Serializable::pop(value, input);
}

template<>
void operator<< <long int>(long int & value, std::istream & input)
{
    Serializable::pop(value, input);
}

template<>
void operator<< <unsigned long int>(unsigned long int & value, std::istream & input)
{
    Serializable::pop(value, input);
}
