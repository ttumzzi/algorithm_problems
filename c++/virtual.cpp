#include <iostream>

class Base {
   public:
    Base() { std::cout << "base class" << std::endl; }

    void what() { std::cout << "base class's what()" << std::endl; }
};
class Derived : public Base {
   public:
    Derived() : Base() { std::cout << "derived class" << std::endl; }

    void what() { std::cout << "derived class's what()" << std::endl; }
};
int main() {
    Base base;
    Derived derived;

    Base* p_derived = &derived;
    Base* p_base = &base;

    std::cout << " == real object is Base == " << std::endl;
    p_base->what();

    std::cout << " == real object is Derived == " << std::endl;
    p_derived->what();

    return 0;
}