#include <iostream>
#include <string>
#include <iomanip>

std::ostream& hex(std::ostream& os) {
	os.setf(std::ios::hex, std::ios::basefield);
	return os;
}

int main() {
	int number;
	for (size_t i = 0; i < 10; ++i) {
		std::cin >> number;
		std::cout << hex << number << std::endl;
	}
	return 0;
}
