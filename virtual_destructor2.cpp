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
