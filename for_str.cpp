#include <iostream>
#include <string>
#include "for_str.hpp"

struct MyStruct{};


template <typename T> 
std::string get_type(T& my_type) {
	if (std::is_same_v<T, MyStruct>) {
		return "MyStruct";
	}
	if (std::is_same_v<T, ctre::SecondStruct>) {
		return "SecondStruct";
	}

	return "";
}

int main() {
	MyStruct my_struct;
	ctre::SecondStruct second_struct;

	std::cout << get_type<MyStruct>(my_struct) << std::endl;
	std::cout << get_type<ctre::SecondStruct>(second_struct) << std::endl;

	std::string hello = "Hello world";

	for (const auto& character : hello) {
		std::cout << character << "|";
	}

}
