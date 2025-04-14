#include <iostream>
#include <type_traits>
#include <utility>

void exec(int& value) {
	std::cout << value << std::endl;
}

void exec(int&& value) {
	std::cout << value << std::endl;
}



template <typename T>
void extract(T&& arg) {
    exec(std::forward<T>(arg));	
    
}



int main() {

	int a = 10;
	extract(a);
	extract(100);

	return 0;
}
