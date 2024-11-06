#include <iostream>
#include <string>

struct s {
	
};

s get_string() {
	return s{};
}

int main() {

	std::string str = "hello world";
	std::cout << *std::begin(str) << " " << *std::end(str);
	std::cout << std::distance(std::begin(str), std::end(str)) << std::endl;
	std::cout << get_string() << std::endl;
}
