#include <iostream>
#include <type_traits>
#include <concepts>
#include <vector>
#include <iterator>


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


template<typename T>
concept Iterator = requires(T it) {
	{ *it } -> std::convertible_to<typename std::iterator_traits<T>::value_type>;
	{ ++it} -> std::same_as<T&>;
};


template<Iterator It>
void print(It begin, It end) {
	while (begin != end) {
		std::cout << *begin << ' ';
		++begin;
	}
	std::cout << '\n';
}


int main() {

	std::cout << square(5) << '\n';
	std::cout << add(2, 2) << '\n';
	std::cout << add(2.2, 3.3) << '\n';

	std::vector<int> vec_data = {1, 2, 3, 4, 5, 6, 7};
	print(vec_data.begin(), vec_data.end());

}
