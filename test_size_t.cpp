#include <iostream>

#include <string>


struct singleline { };
struct multiline { };

struct case_sensitive { };
struct case_insensitive { };


template <size_t Limit> constexpr bool less_than(size_t i) noexcept {
	std::cout << Limit << std::endl;
	if constexpr (Limit == 0) {
		return false;
	}
	else {
		return i < Limit;
	}
}

template <size_t Limit>constexpr size_t out_limit(std::string& str) noexcept {
	
	return str.size();
}

struct flags {
	bool block_empty_match = false;
	bool multiline = false;
	bool case_insensitive = false;

	constexpr flags() = default;
	constexpr flags(const flags&) = default;
	constexpr flags(flags &&) = default;
};

template <typename... Content> struct set {
	template <typename CharT> static constexpr bool match_char(CharT value, const flags& f) noexcept {
	return (Content::match_char(value, f) || ... || false);	
	}
};

template <auto A, auto B> struct char_range {
	template <typename CharT> static constexpr bool match_char(CharT value, const flags& f) noexcept {
		if (value >= "0") {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {

	flags fl;

	using word_chars = set<char_range<'A', 'Z'>>;
	word_chars v;
       	v.match_char('A', fl);

	size_t i {0};
	std::string str = "Hello world";
	std::cout << less_than<32>(i);
	std::cout << out_limit<56>(str);
	return 0;
}
