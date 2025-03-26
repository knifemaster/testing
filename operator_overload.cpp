#include <iostream>
#include <string>
#include <cstdlib>

class MyClass {
    public:
        int value;
        bool is_value;
        MyClass(int v = 0, bool bool_value = true) : value(v), is_value(bool_value) {}

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
        
        bool operator!() const {
            return !is_value;
        }

        bool operator||(const MyClass& other) const {
            return is_value || other.is_value;
        }

        bool operator&&(const MyClass& other) const {
            return is_value && other.is_value;
        }

        bool operator^(const MyClass& other) const {
            return is_value ^ other.is_value;
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


void* operator new(std::size_t size) {
    std::cout << "Выделено " << size << "Байт\n";
    void* p = std::malloc(size);
    if (!p) 
        throw std::bad_alloc();
    return p;
}

void operator delete(void* p) noexcept {
    std::cout << "Освобождена память\n";
    std::free(p);
}


class SecondClass {
    public:
        void* operator new(std::size_t size) {
            std::cout << "Выделено " << size << "Байт для SecondClass\n";
            void* p = std::malloc(size);
            if (!p) 
                throw std::bad_alloc();
            return p;
        }

        void operator delete(void* p) noexcept {
            std::cout << "Освобождена память для SecondClass\n";
            std::free(p);
        }

        void* operator new[](std::size_t size) {
            std::cout << "Выделено " << size << " байт для массива SecondClass\n";
            void* p = std::malloc(size);
            if (!p)
                throw std::bad_alloc();
            return p;
        }

        void operator delete[](void* p) noexcept {
            std::cout << "Освобождена память для массива SecondClass\n";
            std::free(p);
        }
};



int main() {

    {
        int* p = new int(42);
        delete p;
    
        SecondClass* obj = new SecondClass();
        delete obj;

        SecondClass* arr = new SecondClass[10];
        delete[] arr;
    }


    MyClass a(10, true);
    MyClass b(5, false);

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

    std::cout << "a || b: " << (a || b) << std::endl;
    std::cout << "a && b: " << (a && b) << std::endl;
    std::cout << "!a  !b: " << (!a) << " " << (!b) << std::endl;
  
    std::cout << "a ^ b: " << (a ^ b) << std::endl;
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
