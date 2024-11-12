#include <iostream>
#include <string>
#include <type_traits>
#include <typeinfo>

struct Base {};
struct Derived : Base {};

int main() {
	// common_type
	typedef std::common_type<unsigned char, short, int>::type NumericType;

	typedef std::common_type<Derived, Base>::type StructType;

	StructType A;
	NumericType t = 10;

	std::cout << typeid(t).name() << std::endl;
	std::cout << typeid(A).name() << std::endl;	
	std::cout << std::boolalpha;
	std::cout << "Numeric Type " << std::is_same<int, NumericType>::value << std::endl;

	// declval
	

	return 0;
}
