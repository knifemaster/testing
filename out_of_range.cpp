#include <iostream>
#include <stdexcept>
#include <string_view>

int main() {
	std::string_view str_view("abcdef");

	try {
		for (size_t i = 0; true; i++) {
			std::cout << i << " : " << str_view.at(i) << '\n';
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << "Index is out of range \n";
		std::cout << e.what() << '\n';
	}

}

