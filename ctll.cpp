#include <type_traits>

namespace ctll {

template <typename... Ts> struct list { };
	
struct _nothing { };

using empty_list = list<>;

// calculate size of list content
template <typename... Ts> constexpr auto size(list<Ts...>) noexcept { return sizeof...(Ts); }

	
// check if the list is empty
template <typename... Ts> constexpr bool empty(list<Ts...>) noexcept { return false; }
constexpr bool empty(empty_list) { return true; }


// concat two lists together left to right
template <typename... As, typename... Bs> constexpr auto concat(list<As...>, list<Bs...>) noexcept -> list<As..., Bs...> { return {}; }


// push something to the front of a list
template <typename T, typename... As> constexpr auto push_front(T, list<As...>) noexcept -> list<T, As...> { return {}; }


// pop element from the front of a list
template <typename T, typename... As> constexpr auto pop_front(list<T, As...>) noexcept -> list<As...> { return {}; }
constexpr auto pop_front(empty_list) -> empty_list;

// pop element from the front of a list and return new typelist too
template <typename Front, typename List> struct list_pop_pair {
	Front front{};
	List list{};
	constexpr list_pop_pair() = default;
};

template <typename Head, typename... As, typename T = _nothing> constexpr auto pop_and_get_front(list<Head, As...>, T = T()) noexcept -> list_pop_pair<Head, list<As...>> { return {}; }
template <typename T = _nothing> constexpr auto pop_and_get_front(empty_list, T = T()) noexcept -> list_pop_pair<T, empty_list> { return {}; }


// return front of the list
template <typename Head, typename... As, typename T = _nothing> constexpr auto front(list<Head, As...>, T = T()) noexcept -> Head { return {}; }
template <typename T = _nothing> constexpr auto front(empty_list, T = T()) noexcept -> T { return {}; }

// rotate list
template <typename T> struct rotate_item {
	template <typename... Ts> friend constexpr auto operator+(list<Ts...>, rotate_item<T>) noexcept -> list<T, Ts...> { return {}; }
};

template <typename... Ts> constexpr auto rotate(list<Ts...>) -> decltype((list<>{} + ... + rotate_item<Ts>{})) {
	return {};
}

// set operations
template <typename T> struct item_matcher {
	struct not_selected {
		template <typename... Ts> friend constexpr auto operator+(list<Ts...>, not_selected) -> list<Ts...>;
	};
	template <typename Y> struct wrapper {
		template <typename... Ts> friend constexpr auto operator+(list<Ts...>, wrapper<Y>) -> list<Ts...,Y>;
	};

	static constexpr auto check(T) { return std::true_type{}; }
	static constexpr auto check(...) { return std::false_type{}; }
	static constexpr auto select(T) { return not_selected{}; }
	template <typename Y> static constexpr auto select(Y) { return wrapper<Y>{}; }
};

template <typename T, typename... Ts> constexpr bool exists_in(T, list<Ts...>) noexcept {
	return (item_matcher<T>::check(Ts{}) || ... || false);
}

template <typename T, typename... Ts> constexpr auto add_item(T item, list<Ts...> l) noexcept {
	if constexpr (exists_in(item, l)) {
		return l;
	} else {
		return list<Ts..., T>{};
	}
}

template <typename T, typename... Ts> constexpr auto remove_item(T, list<Ts...>) noexcept {
	item_matcher<T> matcher;
	return decltype((list<>{} + ... + matcher.select(Ts{}))){};
}

}

#include <iostream>

#include <string>

struct Triangle {};
struct Line {};
struct Square {};
struct Rectangle {};

template <auto v> struct term {
	constexpr static auto value = v;
	
};

template <size_t Index> struct back_reference {};



int main() {


	 
	const char heart[] = "\xe2\x99\xa5";

	std::cout << heart << '\n';


		
	const char32_t wc[] = U"zß水🍌"; // or "z\u00df\u6c34\U0001f34c"
    	const size_t wc_sz = sizeof wc / sizeof *wc;
    	printf("%zu UTF-32 code units: [ ", wc_sz);
    	for (size_t n = 0; n < wc_sz; ++n)
       		printf("%#x ", wc[n]);
    	printf("]\n");


	char32_t st[1] = {0};
	
	term<'W'> t;
	std::cout << t.value << std::endl;

	ctll::list<Triangle, Line, Rectangle> ls;
	std::cout << ctll::size(ls) << std::endl;
	Rectangle rect;
	ctll::add_item(rect, ls);
	ctll::push_front(back_reference<1>{}, ls);
	//ctll::remove_item(rect, ls);	
	std::cout << ctll::size(ls) << std::endl;



	std::cout << "Hello world" << std::endl;
	return 0;
}

