#include <iostream>

class Grandparent {
public:
    Grandparent() { greet();}

    virtual void greet() = 0;
};

class Parent: public Grandparent {
public:
    Parent() { greet(); }

    virtual void greet() override { std::cout << "Hello from Parent at " << std::hex << this << std::endl; }
};

class Child: public Parent {
public:
    Child() { greet(); }

    virtual void greet() override { std::cout << "Hello from Child at " << std::hex << this << std::endl; }
};


int main(int /* argc */, char ** /* argv */)
{
    auto instance = new Child();
    instance->greet();
    return 0;
}
