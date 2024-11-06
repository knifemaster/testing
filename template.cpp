#include <iostream>
#include <type_traits>
#include <string>
#include <utility>
#include <typeinfo>
struct MyType {
	MyType(int, double, bool) {};
};

struct SecondType {
	SecondType(int a, double b, bool c, float d, std::string e): a(a), b(b), c(c), e(e), d(d) { }
	int a;
	double b;
	bool c;
	float d;
	std::string e;
};

template <typename T, typename ...Args>
T createT(Args&& ...args) {
	return T(std::forward<Args>(args) ...);
}

int main() {
	int lvalue{2024};
	std::string str = "Hello world";
	int uniqZero = createT<int>();
	auto uniqEleven = createT<int>(2011);
	auto uniqTwenty = createT<int>(lvalue);
	auto uniqType = createT<MyType>(lvalue, 3.14, true);
	auto return_data = createT<SecondType>(1, 2.3, true, 3.3, str);
	std::cout << typeid(uniqZero).name() << std::endl;
        std::cout << typeid(uniqEleven).name() << std::endl;
	std::cout << typeid(uniqTwenty).name() << std::endl;
	std::cout << typeid(uniqType).name() << std::endl;	
	std::cout << typeid(return_data).name() << std::endl;

	std::cout << return_data.a << " | " << return_data.b << "|" << return_data.c << "|" << return_data.d << std::endl;
	std::cout << return_data.e << std::endl;
	return 0;
}
