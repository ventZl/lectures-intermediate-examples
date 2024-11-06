#include <iostream>

class ParentA {
public:
    virtual void greet() { std::cout << "Greet from ParentA at " << std::hex << this << std::endl; }
};

class ParentB {
public:
    virtual void greet() { std::cout << "Greet from ParentB at " << std::hex << this << std::endl; }
};

class Child: public ParentA, public ParentB {
public:
    virtual void greet() {
        ParentA::greet();
        ParentB::greet();
        std::cout << "Greet from Child at " << std::hex << this << std::endl;
    }

};

int main(int, char **)
{
    auto instance = new Child();
    instance->greet();
    return 0;
}
