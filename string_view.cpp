#include <iostream>
#include <string_view>
#include <string>

static int alloc;

void* operator new (size_t s) {
    alloc++;
    std::cout << "allocated" << s << std::endl;
    return malloc(s);
}


int main() {

    std::string str1 { "Hello world this is a string" };

    std::string_view str2 { str1.substr(0, 5)};
    std::string_view str3 { str2 };

    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
    std::cout << str3 << std::endl;


    return 0;
}
