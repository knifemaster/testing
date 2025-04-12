#include <iostream>


class A {
public:
    A () {
        std::cout << "constructor A" << "\n";
    }
    virtual ~A() {
        std::cout << "destructor A" << "\n";
    }
};

class B : public A {
public:
    B () {
        std::cout << "constructor B" << "\n";
    }

    ~B() override {
        std::cout << "destructor B" << "\n";
    }
};

int main() {
    {
    // A* ptr = new B();    
     A b = B();
     //A* a = new A();
    //B* b = new B();
    //delete ptr;
    //delete a;
    //delete b;
    }
}
