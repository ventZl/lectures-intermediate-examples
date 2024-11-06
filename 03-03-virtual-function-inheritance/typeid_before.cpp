#include <iostream>
#include <memory>

class Parent {
public:
    Parent() { }

    void greet()  { std::cout << "Hello from Parent" << std::endl; }
};

class Child: public Parent {
public:
    Child() { }

    void greet()  { std::cout << "Hello from Child" << std::endl; }
};

class RichParent {
public:
    RichParent() { }

    virtual void greet() { std::cout << "Hello from RichParent" << std::endl; }
};


class RichChild: public RichParent {
public:
    RichChild() { }

    virtual void greet() { std::cout << "Hello from RichChild" << std::endl; }
};

int main(int /* argc */, char ** /* argv */)
{
    Parent * p_inst = new Child();
    delete p_inst;
    return 0;
}
