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

        operator int() const {
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


int main() {

    MyClass a(10);
    MyClass b(5);

    MyClass c = a + b;
    std::cout << "a + b = " << c << std::endl;

    c = a - b;
    std::cout << "a - b = " << c << std::endl;

    c = a * b;
    std::cout << "a * b = " << c << std::endl;

    c = a / b;
    std::cout << "a / b = " << c << std::endl;

    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;

    ++a;
    std::cout << "После ++a: " << a << std::endl;

    --b;
    std::cout << "После --b: " << b << std::endl;

    std::cout << "a[0] = " << a[0] << std::endl;

    std::cout << "a(5) = " << a(5) << std::endl;

    int x = a;
    std::cout << "Приведение к int: " << x << std::endl;

    std::cout << "Введите новое значение для a: ";
    std::cin >> a;
    std::cout << "Новое значение a: " << a << std::endl;


    return 0;
}
