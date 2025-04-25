#include <iostream>

template <typename T>
class Counter {
    public:
        static int count;

        Counter() { ++count; }
        ~Counter() { --count; }

        static void PrintCount() {
            std::cout << "Total objects: " << count << std::endl;
        }
};

template <typename T>
int Counter<T>::count = 0;

class MyClass : public Counter<MyClass> {};



template <typename Derived>
class Animal {
public:
    void Speak() {
        static_cast<Derived*>(this)->SpeakImpl(); // Вызов метода производного класса
    }
};


class Dog : public Animal<Dog> {
public:
    void SpeakImpl() {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal<Cat> {
public:
    void SpeakImpl() {
        std::cout << "Meow!" << std::endl;
    }
};

template <typename Derived>
class Shape {
    public:
        int Area() {
            static_cast<Derived*>(this)->AreaImpl();
        }
};

class Rectangle : public Shape<Rectangle> {
    public:
        explicit Rectangle(int m_sideA, int m_sideB) : m_sideA(m_sideA), m_sideB(m_sideB) {}
        int AreaImpl() {
            std::cout << "rectangle area" << std::endl;
            return m_sideA * m_sideB;
        }
    private:
        int m_sideA;
        int m_sideB;
};

class Triangle : public Shape<Triangle> {
    public:
        explicit Triangle(int m_side, int m_height): m_side(m_side), m_height(m_height) {}
        int AreaImpl() {
            std::cout << "triangle area" << std::endl;
            return (m_side * m_height) / 2;
        }
    private:
        int m_side;
        int m_height;    
};

int main() {
    MyClass a, b, c;
    MyClass::PrintCount();

    Dog dog;
    Cat cat;

    dog.Speak(); // Woof!
    cat.Speak(); // Meow!

    return 0;

}
