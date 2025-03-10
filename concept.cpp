#include <iostream>
#include <type_traits>
#include <concepts>


template<typename T>
concept Integral = std::is_integral_v<T>;

template<Integral T>
T square(T x) {
	return x * x;
}


template<typename T>
concept Addable = requires(T a, T b) {
	{ a + b } -> std::convertible_to<T>;
};

template<Addable T>
T add(T a, T b) {
	return a + b;
};



int main() {

	std::cout << square(5) << '\n';
	std::cout << add(2, 2) << '\n';
	std::cout << add(2.2, 3.3) << '\n';
}
