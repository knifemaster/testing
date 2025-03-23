#include <iostream>
#include <string>

class MyClass {
    public:
        int value;
        
        MyClass(int v = 0) : value(v) {}

        MyClass operator+(const MyClass& other) const {
            return MyClass(value + other.value);
        }

        MyClass operator-(const MyClass& other) const {
            return MyClass(value - other.value);
        }

        MyClass operator*(const MyClass& other) const {
            return MyClass(value * other.value);
        }

        MyClass operator/(const MyClass& other) const {
            if (other.value == 0) {
                throw std::runtime_error("Деление на ноль!");
            }
            return MyClass(value / other.value);
        }

        MyClass& operator=(const MyClass& other) {
            if (this != &other) {
                value = other.value;
            }
            return *this;
        }
        
        bool operator==(const MyClass& other) const {
            return value == other.value;
        }

        bool operator!=(const MyClass& other) const {
            return value != other.value;
        }
        
        bool operator<(const MyClass& other) const {
            return value < other.value;
        }

        bool operator>(const MyClass& other) const {
            return value > other.value;
        }

        bool operator<=(const MyClass& other) const {
            return value <= other.value;
        }

        bool operator>=(const MyClass& other) const {
            return value >= other.value;
        }

        MyClass& operator++() { // Префиксный инкремент
            ++value;
            return *this;
        }

        MyClass operator++(int) { // Постфиксный инкремент
            MyClass temp = *this;
            ++(*this);
            return temp;
        }

        MyClass& operator--() { // Префиксный декремент
            --value;
            return *this;
        }

        MyClass operator--(int) { // Постфиксный декремент
            MyClass temp = *this;
            --(*this);
            return temp;
        }

        int& operator[](int index) {
            if (index != 0) {
                throw std::out_of_range("Индекс должен быть 0");
            }
            return value;
        }

        int operator()(int x) const {
            return value + x;
        }

        int operator int() const {
            return value;
        }

        friend std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
            os << obj.value;
            return os;
        }

        friend std::istream& operator>>(std::istream& is, MyClass& obj) {
            is >> obj.value;
            return is;
        }


};
