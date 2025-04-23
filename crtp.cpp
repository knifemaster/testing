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

int main() {
    MyClass a, b, c;
    MyClass::PrintCount();
    return 0;

}
