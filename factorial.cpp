#include <iostream>
#include <type_traits>

template <unsigned n>
struct factorial : std::integral_constant<int, n*factorial<n-1>::value> {};

template <>
struct factorial<0> : std::integral_constant<int, 1> {};

int main() {
	std::cout << factorial<6>::value;
	return 0;
}
