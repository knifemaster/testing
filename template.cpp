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

template<typename T>
T Sum(T arg) {
	return arg;
}

template <typename T, typename... Args>
T Sum(T start, Args... args) {
	return start + Sum(args...);
}

template <typename ... Args> size_t f(Args ... args) {
	return sizeof...(args);
}

int main() {
	MyType t(32, 3.2, true);
	MyType t2(42, 4.2, true);
	std::cout << f(t, t2) << std::endl;

	std::cout << Sum(1, 2, 3, 4, 5) << std::endl;

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
