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

constexpr bool find_number_in_array(const std::array<int, 9>& arr, int size, int number) noexcept {
	for (int i = 0; i < size; ++i) {
		if (arr[i] == number) {
			return true;
		}
	}
	return false;
}

class String {
	const char* p;
	size_t sz;

	public:
		template<size_t N>
		constexpr String(const char(&a)[N]): p(a), sz(N - 1) {}

		constexpr char operator[](size_t n) const {
			return n < sz ? p[n] : throw std::out_of_range("");
		}

		constexpr size_t size() const { return sz; }
};


int main() {

	const char* message = "Hello world";

	String s("hello world");

	std::cout << s[1] << std::endl;

	std::cout << message << std::endl;

	std::array<int, 9> arr {1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::cout << find_number_in_array(arr, 9 , 5) << std::endl;

	constexpr int num = get_number(50, 100);

	std::cout << num << std::endl;

	std::cout << example<int, float>::template get<100>() << std::endl;



	return 0;
}
