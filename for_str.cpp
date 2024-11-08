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

template <typename ...Content>
void print_list_types(Content ...content) {
	(std::cout << ... << get_type(content)) << "\n";
}

int main() {
	MyStruct my_struct;
	ctre::SecondStruct second_struct;

	std::cout << get_type(my_struct) << std::endl;
	std::cout << get_type(second_struct) << std::endl;
	print_list_types(my_struct, second_struct);
	std::string hello = "Hello world";

	for (const auto& character : hello) {
		std::cout << character << "|";
	}

}
