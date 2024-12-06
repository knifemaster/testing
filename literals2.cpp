#include <string>
#include <iostream>


long double operator ""_km(long double val) {
	return val;	
}

long double operator ""_sm(long double val) {
	return val;
}

int main() {

	auto x = 10.9_km;
	std::cout << x << " kilometers " << std::endl;
	
	auto values = 30.54_sm;
	std::cout << values << " santimeters "<< std::endl;
	
	return 0;
}
