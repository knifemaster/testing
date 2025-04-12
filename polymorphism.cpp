#include <iostream>
#include <string>
#include <exception>
#include <vector>

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

class Animal {
    public:
    virtual void eat() = 0;
    virtual void walk() = 0;
    virtual void fly() = 0;
    virtual void run() = 0;

};

class Bird : public Animal {
    public:
    void eat() override {
        std::cout << "Bird eats" << "\n";
    }
    void walk() override {
        std::cout << "Bird walks" << "\n";
    }
    void fly() override {
        std::cout << "Bird fly" << "\n";
    }
    void run() override {
        std::cout << "Bird run" << "\n";
    }
};

class Cat : public Animal {
    public:
    void eat() override {
        std::cout << "cat eats" << "\n";
    }
    void walk() override {
        std::cout << "cat walks" << "\n";
    }
    void fly() override {
        std::cout << "cat fly" << "\n";
    }
    void run() override {
        std::cout << "cat run" << "\n";
    }

};


int main() {

    std::vector<Animal*> animals;

    Animal* bird = new Bird();
    Animal* cat = new Cat();
    animals.emplace_back(bird);
    animals.emplace_back(cat);
    
    for (const auto& animal : animals) {
        animal->walk();
    }
    
    bird->fly();

    Base* b = new Derrived();
    b->Hello();
    std::cout << "\n";
    Base c = Derrived();
    c.Hello();
    b->SimpleFunction();

    return 0;
}


