#include <iostream>
#include <string>

struct Container {
	public:	
		Container(int val): value(val) {}
		
		int get_value() {
			return value;
		}
	private:
		int value; 
};

Container b{50};

decltype(b) get_struct(decltype(b) container) {
	decltype(b) ret_value = container;
	return ret_value;
}

int main() {
	Container cont {555};
	auto container_value = get_struct(cont);
	std::cout << container_value.get_value() << std::endl;
	std::string str1 = "Hello world";
	decltype(str1) str2 = str1;

	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;
	return 0;
}
