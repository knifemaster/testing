#include <iostream>
#include <string>
#include <vector>

constexpr int evaluate(int val) {
	if (val < 10) {
		return 5;
	}
	else {
		return val * 10;
	}
}

std::string get_string() {
	return "hello world";
}

int main() {

	constexpr int result = evaluate(11);
	std::string str = get_string();
	std::cout << result << std::endl;
	std::cout << str << std::endl;

	return 0;
}
