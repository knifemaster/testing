#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <vector>
#include <cmath>

int main() {

	using namespace boost::multiprecision;

	unsigned int modul = std::pow(10, 9) + 7;

	std::cout << modul << std::endl;

	std::vector<int256_t> factorials;
	factorials.reserve(109);
	int256_t v = 1;

	for(unsigned i = 1; i <= 109; ++i) {
		v *= i;
		factorials.push_back(v);
		std::cout<< i << " === " << v % modul<< std::endl;
	}

	for(unsigned i = 109;  i > 0; i--) {
		v /= i;
		std::cout << i << " === " << v % modul << std::endl;
	}

	for (const auto& factorial : factorials) {
		std::cout << factorial << std::endl;
	}


}
