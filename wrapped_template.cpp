#include <iostream>
#include <vector>
#include <array>
#include <string>




template <typename T, typename U>
struct example {
	template <size_t V>
	static constexpr int get() {
		return V;
	}

};

constexpr int get_number(int number, int end) noexcept {
	for (size_t i = 0; i < end; i++) {
		if (i == number) {
			return number*number;
		}
	}

	return 0;

}

constexpr bool find_number_in_array(std::array<int, 9>& arr, int size, int number) noexcept {
	for (int i = 0; i < size; ++i) {
		if (arr[i] == number) {
			return true;
		}
	}
	return false;
}

int main() {

	std::array<int, 9> arr {1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::cout << find_number_in_array(arr, 9 , 5) << std::endl;

	constexpr int num = get_number(50, 100);

	std::cout << num << std::endl;

	std::cout << example<int, float>::template get<100>() << std::endl;



	return 0;
}
