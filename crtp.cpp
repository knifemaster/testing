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




int main() {
    MyClass a, b, c;
    MyClass::PrintCount();
    return 0;

}
