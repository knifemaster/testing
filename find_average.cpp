#include <iostream>
#include <cstdarg>
#include <type_traits>
#include <typeinfo>

double findAverage(int first, ...) {
	double sum = first;
	va_list list;
	va_start(list, first);

	int count = 1;

	while(1) {
		int arg = va_arg(list, int);

		if (arg == -1) break;
		std::cout << arg << typeid(arg).name() <<std::endl;
		sum+= arg;
		count++;
	}

	va_end(list);
	return sum / count;

}

int main() {
	std::cout << findAverage(1, 2, 3, 4, -1) << '\n';
	std::cout << findAverage(1, 2, 3, 4, 5, -1) << '\n';

	return 0;
	
}
