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

    std::string_view sv = "Programming";

    sv.remove_prefix(3);  // Удаляем первые 3 символа
    std::cout << sv << '\n';  // "gramming"

    sv.remove_suffix(4);  // Удаляем последние 4 символа
    std::cout << sv << '\n';  // "gram"

    
    std::string_view sv2 = "C++ is great, C++ is powerful!";

    // Поиск подстроки
    size_t pos = sv2.find("C++");
    std::cout << "First 'C++' at: " << pos << '\n';  // 0

    pos = sv2.find("Python");
    if (pos == std::string_view::npos) {
        std::cout << "Substring not found!\n";
    }

    // Поиск с конца (rfind)
    pos = sv2.rfind("C++");
    std::cout << "Last 'C++' at: " << pos << '\n';  // 14

    // Получение подстроки
    std::string_view sub = sv2.substr(7, 8);
    std::cout << "Substring: " << sub << '\n';  // "great, C"


    return 0;
}
