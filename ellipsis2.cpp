#include <iostream>
#include <typeinfo>
#include <utility>

template <typename T>
void print_type(const T&) {
	std::cout << typeid(T).name() << std::endl;
}

void print_argument_types() {}

template <typename First, typename... Rest>
void print_argument_types(const First& first, const Rest& ... rest) {
	print_type(first);
	print_argument_types(rest...);
}

template <typename... Content>void calculate(Content... content) {
	print_argument_types(content ...);

}


int main() {
	int i = 10;
	double d = 10.10;
	std::string s = "Hello world";

	print_argument_types(i, d, s);
	calculate(i, d, s);
	return 0;

}
