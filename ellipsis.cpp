#include <iostream>

void print() {}

template <typename T, typename ... Types>
void print(T firstArg, Types ... args) {
	std::cout << firstArg << "\n";
	print(args...);
}

template <typename ...args>
inline void print_args(args&&... a) {
	((std::cout << a << std::endl), ...);
}

int main() {
	print("hello", 1324, 43.56, "World");
	print_args(1, 2, 3, 4, "hello");
}
