#include <iostream>
#include <vector>
#include <array>
#include <string>




template <typename T, typename U>
struct example {
	template <typename V>
	static constexpr int get() {
		return 42;
	}

};


int main() {

	std::cout << example<int, float>::template get<double>() << std::endl;



	return 0;
}
