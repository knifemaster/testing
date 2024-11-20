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


int main() {

	std::cout << example<int, float>::template get<100>() << std::endl;



	return 0;
}
