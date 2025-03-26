#include <iostream>

struct Base {
    Base() {
        print();
    }

    void print() {
        print_impl();
    }

    private:
        virtual void print_impl() = 0;

};

struct Derived : Base {
    void print_impl() override {
        std::cout << "print_impl" << "\n";
    }
};

int main() {

    Derived derived;
    return 0;
}
