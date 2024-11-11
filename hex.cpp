#include <iostream>
#include <string>
#include <iomanip>

std::ostream& hex_out(std::ostream& os) {
	os.setf(std::ios::hex, std::ios::basefield);
	return os;
}

int main() {
	int number;
	for (size_t i = 0; i < 10; ++i) {
		std::cin >> number;
		std::cout << hex_out << number << std::endl;
	}
	return 0;
}
