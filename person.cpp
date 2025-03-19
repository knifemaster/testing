#include <iostream>
#include <utility>
#include <string>


class Person {
	private:
		std::string name;
		int age;
	
	public:
		Person() : name("Unknown"), age(0) {
			std::cout << "default constructor"
		}


};
