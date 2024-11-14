#include <iostream>
#include <type_traits>


template <typename Begin> 
void calculate_first(Begin begin) {
	std::cout << begin << std::endl;
}

template <typename Begin, typename... Tail, typename... Content>
void calculate_first(Begin begin, Tail... tail) {
	std::cout << begin << std::endl;
	std::cout << sizeof...(tail) << std::endl;
	
	if (sizeof...(tail) > 0) {
		calculate_first(tail...);
	}

}


int main() {
	calculate_first(10, 25.25, "Hello world");
}
