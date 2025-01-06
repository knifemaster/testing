#include <iostream>
#include <string>
#include <boost/type_index.hpp>
#include <vector>

namespace ctll {

template <typename... Ts> struct list {

};

}

void printContentTypes() {}

template <typename First, typename... Rest>
void printContentTypes(const First& first, const Rest&... rest) {
	std::cout << boost::typeindex::type_id_with_cvr<First>().pretty_name() << std::endl;
	printContentTypes(rest...);
	
}

struct can_be_anything {};
struct accept {};
struct start_mark{};

template <typename... Content> void calculate(Content... content) {
	printContentTypes(content ...);
}


template <typename... Content>
auto first(Content ...) {
	std::vector<boost::typeindex::type_index> types = {boost::typeindex::type_id<Content>()...};

	std::cout << types.size() << std::endl;
	for (const auto& type : types) {
		std::cout << type.pretty_name() << std::endl;
	}	
}

template <typename... Content>
auto check(ctll::list<Content...>) {
	std::vector<boost::typeindex::type_index> types = {boost::typeindex::type_id<Content>()...};
	std::cout << "size*************************************" << std::endl;
	std::cout << types.size() << std::endl;
	for (const auto& type : types) {
		std::cout << type.pretty_name() << std::endl;
	}
	std::cout << "size*************************************" << std::endl;	
}

int main() {

	ctll::list<can_be_anything, accept, start_mark> list_args;

	check(list_args);

	int i = 10;
	double d = 10.10;
	std::string s = "hello world";

	can_be_anything a;
	accept b;
	start_mark c;


	printContentTypes(i, d, s);
	printContentTypes(a, b, c);
	calculate(a, b, c);

	std::cout << "****************************"<< std::endl;
	first(a, b, c);

	return 0;

}
