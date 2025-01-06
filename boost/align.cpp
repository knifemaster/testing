#include <iostream>
#include <boost/align.hpp>
#include <string>

int main() {
	using MyString = std::basic_string<char, std::char_traits<char>, 
	      boost::alignment::aligned_allocator<char, 512>>;

	for (size_t i = 0; i < 100; i++) {
		MyString str = "hello world";
		std::cout<< (((int64_t)str.data()%(512/8))== 0 ? "true": "false")<<std::endl;
	}

	MyString st = "Hello worldfhdasjksfhjkdsahfjkdsahfjkhdsajkfhdasjkfhdjksafhjkdsahfjkdsahfjkdsahfjhdsa";

	std::cout << sizeof(st.capacity()) << std::endl;

	return 0;
}

