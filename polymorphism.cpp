#include <generator>
#include <ranges>
#include <print>
#include <iostream>
#include <string>
#include <exception>

class Base {
    public:
    Base() {
        std::cout << "Base constructor" << "\n";
    }
    virtual void Hello() {
        std::cout << "virtual function of base" << "\n";
    }
    void SimpleFunction() {
        std::cout << "Base Simple Function" << "\n";
    }
};

class Derrived : public Base {
    public:
    Derrived() {
        std::cout << "Derrived constructor" << "\n";
    }
    void Hello() override {
        std::cout << "virtual function of Derrived" << "\n";
    }
    void SimpleFunction() {
        std::cout << "SimpleFunction" << "\n";
    }
};


int main() {

    Base* b = new Derrived();
    b->Hello();
    std::cout << "\n";
    Base c = Derrived();
    c.Hello();
    b->SimpleFunction();

    return 0;
}


