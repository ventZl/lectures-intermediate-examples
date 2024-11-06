#include <iostream>
#include <memory>

class Parent {
public:
    Parent() {  }

    void greet()  { std::cout << "Hello from Parent at " << std::hex << this << std::endl; }
};

class Child: public Parent {
public:
    Child() { }

    void greet()  { std::cout << "Hello from Child" << std::hex << this << std::endl; }
};

class RichParent {
public:
    RichParent() { }

    virtual void greet() { std::cout << "Hello from RichParent" << std::hex << this << std::endl; }
};


class RichChild: public RichParent {
public:
    RichChild() { }

    virtual void greet() { std::cout << "Hello from RichChild" << std::hex << this << std::endl; }
};

int main(int /* argc */, char ** /* argv */)
{
    Parent * p_inst = new Child();

    RichParent * p_rich = new RichChild();
    std::cout << "`instance` type = " << typeid(*p_inst).name() << std::endl;
    std::cout << "`rich_instance` type = " << typeid(*p_rich).name() << std::endl;
    return 0;
}
