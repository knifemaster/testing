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



};
