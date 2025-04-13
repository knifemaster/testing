#include <iostream>
#include <string>
#include <exception>
#include <vector>


class Base {
    public:
        Base() {
            std::cout << "Base ctor\n";
        }

        virtual void print() {
            std::cout << "Base print\n";
        }

        virtual ~Base() {
            std::cout << "Base dtor\n";
        }

};


class Derived : public Base {
    public:
        Derived() {
            std::cout << "Derived ctor\n";
        }

        void print() override {
            std::cout << "Derived print\n";
        }

        ~Derived() {
            std::cout << "Derived dtor\n";
        }

};


int main() {
    Derived b = Derived();
    Base* c = &b;
    c->print(); // Derived print
    Base bs = Derived();
    bs.print(); // Base print
    
    //delete c; if we delete c invalid pointer exception
    return 0;
}

