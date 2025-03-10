#include <iostream>
#include <type_traits>
#include <concepts>


template<typename T>
concept Integral = std::is_integral_v<T>;

template<Integral T>
T square(T x) {
	return x * x;
}


int main() {

	std::cout << square(5) << '\n';
}
