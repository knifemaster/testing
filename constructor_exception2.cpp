#include <generator>
#include <ranges>
#include <print>
#include <iostream>
#include <string>
#include <exception>

class Int {
    int value;
public:
    // "Перегруженные конструкторы" (на самом деле конструкторы класса)
    Int() : value(0) { std::cout << "Default constructor (0)\n"; }
    Int(int x) : value(x) { std::cout << "Constructor (" << x << ")\n"; }
    Int(const Int& other) : value(other.value) { std::cout << "Copy constructor\n"; }

    // "Деструктор" (вызывается при уничтожении объекта)
    ~Int() { std::cout << "Destructor (" << value << ")\n"; }

    // Оператор преобразования в int
    operator int() const { return value; }
};

class B {
    public:
    B() {
        std::cout << "constructor B" << "\n";
    }
    ~B() {
        std::cout << "destructor B" << "\n";
    }
};


class S {
    public:
    S(std::string& name, int b, B* ptr, std::string& surname) {
        std::cout << "i am constructor before exception" << "\n";
        b_ptr = new B();
        name = name;
        b = b;
        B bb = B();
        Int a;       // Вызовет конструктор по умолчанию
        Int c(42); 
        throw std::exception();
        std::cout << "Constructor after exception" << "\n";
        ptr_b = ptr;
        surname = surname;

    }
    private:
        B* b_ptr;
        std::string name;
        int b;
        B* ptr_b;
        std::string surname;        
};

int main() {
    std::string name = "Joe";
    int b = 42;
    B* pt = new B();
    std::string surname = "Doe";
    try {
        S* s = new S(name, b, pt, surname);
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    
    }
}

