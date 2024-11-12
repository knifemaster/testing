#include <iostream>
#include <type_traits>
#include <typeinfo>

struct Base {};
struct Derived : Base {};

Base b;

using value_type = decltype(b);

value_type current_match {};

int main() {
	Derived a;
	current_match = decltype(a){};
	decltype(a) d;	
	Derived c;
	std::cout << typeid(current_match).name() << std::endl;
	std::cout << typeid(c).name() << std::endl;
	std::cout << typeid(d).name() << std::endl;
	return 0;
}
