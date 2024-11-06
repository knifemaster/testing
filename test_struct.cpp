#include <iostream>
#include <typeinfo>
#include <type_traits>
#include <vector>
#include <iterator>
#include <algorithm>
namespace ctre {
	struct singleline {};
	struct multiline {};
	struct case_sensitive {};

	template<typename Flag> 
	void print_flag_name(Flag& flag) {
		std::cout << typeid(flag).name() << std::endl;
	
	}

}

template <typename... Ts> struct list {};

template <typename... Ts> auto size(list<Ts...>) {
	return sizeof...(Ts);
}

template <typename... Ts> void print_list_types(list<Ts...> list_types) {
	//std::cout << typeid(Ts...).name() << std::endl;
	//for (const auto type : list_types) {
	//	std::cout << typeid...(type).name() << std::endl;
	//}
	//return typeid...(Ts).name()

}

struct Person {
};

template<typename Iterator>
struct BeginIterator {
	Iterator b;
	void print_type() {
		std::cout << typeid(Iterator).name() << std::endl;
	}
};

template<typename T>
void print_types(T a) {
	std::cout << typeid(T).name() <<std::endl;
}

struct Begin{};
struct End{};
struct current{};

template <auto A, auto B> struct char_range {

};

template <typename T> bool is_ascii_alpha_lowercase(T v) {
	return (v >= static_cast<T>('a')) && (v <= static_cast<T>('z'));
}

//template <auto A, auto B>  void populate(ctre::char_range<A,B>) {
//	insert(A,B);
//}

void print() {
	std::cout << std::endl;
}

template <typename T> void print(const T& t) {
	std::cout << t << std::endl;
}

template <typename First, typename ... Rest> void print(const First& first, const Rest&... rest) {
	std::cout << first << ", ";
	print(rest...);
}

struct A {};
struct B {
	virtual void fn() = 0;
};


int main() {


	print(100, 200, 300);
	std::cout << std::boolalpha << std::is_abstract<B>::value << std::endl;
	std::cout << "char " << std::alignment_of<char>::value << std::endl;
        std::cout << "int " << std::alignment_of<int>::value << std::endl; 	

	std::cout << static_cast<char>('a')<< std::endl;
	std::cout << is_ascii_alpha_lowercase('g')<< std::endl;
	//char_range<"a", "z"> range;
	//std::cout <<

	list<Begin, End, current> my_list {};
	std::cout << size(my_list) <<std::endl;
	print_list_types(my_list);

	Person person;
	BeginIterator<Person> bi;
	std::cout << typeid(Person).name() << std::endl;
	bi.print_type();
	print_types<Person>(person);
	print_types<BeginIterator<Person>>(bi);
	ctre::singleline v;
	ctre::print_flag_name<ctre::singleline>(v);
	
	ctre::multiline ml;
	ctre::print_flag_name(ml);
	return 0;

}
