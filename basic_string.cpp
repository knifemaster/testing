#include <iostream>
#include <string>
#include <type_traits>
#include <iterator>
#include <typeinfo>
#include <vector>
#include <limits>
#include <cstdint>

//#include "reflect-cpp/include/rfl.hpp"
//#include "reflect-cpp/include/rfl/json.hpp"

template <size_t Id> struct captured_content {
	template <typename Iterator> class storage {
		Iterator _begin {};
		Iterator _end {};
	};
};

template <typename Iterator> struct iterator {
	Iterator _begin {};
	Iterator _end {};

	auto get_address() {
		return &_begin;
	}
	auto get_address_end() {
		return &_end;
	}
};
template<typename Iterator>
struct simple_struct {
	Iterator a{};
	Iterator b{};
	friend std::ostream& operator<<(std::ostream& os, simple_struct& str) {
		os << str.a << typeid(Iterator).name();
		return os;
	}

	auto get_begin() {
		return a;
	}
	auto get_end() {
		return b;
	}
	void set_begin(Iterator a) {
		a = a;
	}
	void set_end(Iterator b) {
		b = b;
	}
};

template<typename bi_directional_iterator>
void reverse_arr(bi_directional_iterator first, bi_directional_iterator last, int number) {
	//typename std::iterator_traits<bi_directional_iterator>::difference_type n = std::distance(first, last);
	//--n;
	//while(n > 0) {
	//	typename std::iterator_traits<bi_directional_iterator>::value_type tmp = *first;
	//	*first++ = *--last;
	//	*last = tmp;
	//	n -= 2;
	//}

	while(first != last) {
		std::cout << *first;
		first++;
		if (*first == number) {
			std::cout << "finded " << *first << std::endl;		
			break;
		}	
	}
}


struct not_matched_t {};
struct matched_t {};

template <typename matched>
struct Match {
	//using result = std::conditional_t<std::is_same_v<matched, matched_t>, matched_t, not_matched_t>
	
	//void print(result r) {
		//std::cout << r << std::endl
	//}

};

template <bool B, typename T, typename F> struct TypeMatch {
	using type = typename std::conditional<B,T,F>::type;
	using type2 = typename std::conditional<!B, T, F>::type;
	type A{};
	type2 C{};
};

struct Test {
	int a{};
	int b{};
	void print_address() {
		std::cout << this << " " << &this->b << std::endl;
	}
};

template <typename ResultIterator = void, typename BeginIterator = int, typename EndIterator = double> struct Result {
	using result = std::conditional_t<std::is_same_v<ResultIterator, void>, BeginIterator, EndIterator>;
	result A{};
};


double sum(double x) {
	return x;
}

template <typename... Args>
double sum(double x, Args... args) {
	return x + sum(args...);
}

template <typename... Args>
void print_args(Args... args) {
	(std::cout << ... <<  typeid(args).name())<< " " << "\n";
}

struct Rectangle {
	int size {};
};

struct Triangle {
	bool flag_case_sensitive = false;
};

struct Line {};
struct Circle {};
struct Square {};
//using Shapes = rfl::TaggedUnion<"shape", Circle>;

template<typename T>
std::string get_structs_name(T& object) {
	if (std::is_same_v<T, Triangle>) {
		return "Triangle";
		//std::cout << "Triangle" << std::endl;
	}
	if (std::is_same_v<T, Rectangle>) {
		return "Rectangle";
		//std::cout << "Rectangle" << std::endl;
	}
	if (std::is_same_v<T, Line>) {
		return "Line";
		//std::cout << "Line" << std::endl;
	}
	if (std::is_same_v<T, Circle>) {
		return "Circle";
		//std::cout << "Circle" << std::endl;
	}
	if (std::is_same_v<T, Square>) {
		return "Square";
		//std::cout << "Square" << std::endl;
	}
}

template <typename ...Args>
void print_list_types(Args ...args) {
	(std::cout << ...<< get_structs_name(args)) << "\n";
}


template <typename Rectangle, typename Triangle, typename Square> int evaluate(Rectangle begin,Triangle end, Square data ) {
	print_list_types(begin, end, data);
	if (begin.size >= 5) {
		return 1;
	}

	if (begin.size == 2) {
		end.flag_case_sensitive = true;
	}

	if (end.flag_case_sensitive == true) {
		return 2;
	}
	begin.size++;
	return evaluate(begin, end, data);
}

namespace ctll {
	template <typename... Ts> struct list{};
	struct _nothing {};
	using empty_list = list<>;

	template <typename... Ts> constexpr auto size(list<Ts...>) noexcept { return sizeof...(Ts); }

	template <typename... Ts> constexpr bool empty(list<Ts...>) noexcept { return false; }
	constexpr bool empty(empty_list) { return true; }

	template <typename... As, typename... Bs> constexpr auto concat(list<As...>, list<Bs...>) noexcept -> list<As..., Bs...> { return {}; }

	template <typename T, typename... As> auto push_front(T type, list<As...> lst) noexcept -> list<T, As...> { 
		//std::cout << "hellow" << std::endl;
		print_list_types(type);
		//std::cout << typeid(T).name() << std::endl;
		
		//std::cout << "worldw" << std::endl;
		return {}; }

	template <typename T, typename... As> constexpr auto pop_front(list<T, As...>) noexcept -> list<As...> { return {}; }
constexpr auto pop_front(empty_list) -> empty_list;

template <typename Front, typename List> struct list_pop_pair {
	Front front{};
	List list{};
	constexpr list_pop_pair() = default;
};

	//template <typename list<As...>> auto get_params_names(list<As...> lst) {
	//	return ""
		//print_list_types(As(...));
	//}	
	
}

int main() {
	ctll::list lst;
	int q;
	Triangle tri;
	Circle circl;
	Line lin;
	ctll::push_front(tri, lst);
	ctll::push_front(circl, lst);
	ctll::push_front(lin, lst);
	std::cout << "()begin" << std::endl;
	std::cout << ctll::size(lst);
	std::cout << ctll::empty(lst);
	std::cout << "()end" << std::endl;
	//ctll::pop_front(tri);


	Rectangle rectangle;
	Triangle triangle;
	Square square;
	Line line;
	Circle circle;

	evaluate(rectangle, triangle, square);
	std::cout << "Hello world" << std::endl;

	print_list_types(rectangle, triangle, square, line, circle);

//	print_structs(line);
//	print_structs(circle);
//	print_structs(sq);
//	print_structs(tri);
//	print_structs(rect);
	//std::cout << print_structs(tri) << print_structs(rect) << std::endl;

//	Shapes r = Circle{.radius=10.10};

//	auto json_string = rfl::json::write(r);

//	std::cout << json_string << std::endl;

	not_matched_t nmt;
	matched_t mt;
	std::string name = "hello world";
	print_args(nmt, mt, name);
	print_args(1, 2, 3, 4, 4.4, 5.5);
	print_args<int, float, double>(5, 44.4, 44.4);

	Result<void, int, double> res;
        std::cout << typeid(res.A).name() << std::endl;	

	std::cout << (std::numeric_limits<uint32_t>::max)() << std::endl;

	Test t;
	Test k;
	t.print_address();
	k.print_address();


	TypeMatch<false, double, int> types;
	types.A = 32;	
	types.C = 32.8590483;
	std::cout << types.A << typeid(types.A).name() << std::endl;
	std::cout << types.C << typeid(types.C).name() << std::endl;

	using Type1 = std::conditional<true, int, double>::type;
	using Type2 = std::conditional<false, int, double>::type;
	using Type3 = std::conditional<sizeof(int) <= sizeof(double), int, double>::type;
	std::cout << typeid(Type1).name() << std::endl;	
	std::cout << typeid(Type2).name() << std::endl;
	std::cout << typeid(Type3).name() << std::endl;


	std::vector<int> v {1, 2, 3, 4, 5, 6};
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	reverse_arr(arr, arr + 10, 5);
	reverse_arr(v.begin(), v.end(), 4);

	for (int n : v) {
		std::cout << n << ' ';
	}


	typedef std::iterator_traits<int*> traits;
	if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
		std::cout << "int* is random access iterator"<<std::endl;

	if (typeid(traits::value_type)==typeid(int))
		std::cout << "value type is int" << std::endl;

	simple_struct<int> structure;
	std::string stri = "hello world";
	structure.set_begin(1);
	structure.set_end(10);

	//std::cout << "adress of stri"  << &std::begin(stri) << std::endl;
	std::cout << "distance" << std::end(stri) - std::begin(stri) << std::endl;
	
	std::cout << *std::begin(stri) << std::endl;
	std::cout << std::distance(std::begin(stri), std::end(stri)) << std::endl;
	//std::cout << std::distance(structure.get_begin(), structure.get_end()) << std::endl;	
	iterator<double> it{};

	std::cout << it.get_address() << std::endl; 
	std::cout << it.get_address_end() << std::endl;
	std::cout << it.get_address_end() - it.get_address() << std::endl;
	
	std::string str = "hello world";
	std::cout << str.size() << std::endl;
	str[3] = '\000';
	std::cout << str.data() << std::endl;
	captured_content<1> cap ;
	//std::cout << cap._begin;
}
