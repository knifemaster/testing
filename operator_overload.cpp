#include <iostream>
#include <string>

class MyClass {
    public:
        int value;
        
        MyClass(int v = 0) : value(v) {}

        MyClass operator+(const MyClass& other) const {
            return MyClass(value + other.value);
        }

};
