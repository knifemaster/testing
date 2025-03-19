#include <iostream>
#include <utility>
#include <string>


class Person {
    private:
        std::string name;
        int age;

    public:
        Person() : name("Unknown"), age(0) {
            std::cout << "default constructor"<< '\n';
        }

        Person(std::string name, int age) : name(std::move(name), age(age)) {
            std::cout << "parametrized constructor" << '\n';
        }

        Person(const Person& other) : name(other.name), age(other.age) {
            std::cout << "copy constructor" << "\n";
        }

        Person& operator=(const Person& other) {
            if (this != &other) {
                name = other.name;
                age = other.age;
                std::cout << "copy assignment operator" << "\n";
            }
            return *this;
        }



};
