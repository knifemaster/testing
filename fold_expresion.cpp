#include <iostream>
#include <type_traits>
#include <vector>

template <class... Args>
constexpr auto Sum(Args... args) {
    return (... + args);
}

int a() {
    std::cout << "A" << std::endl;
    return 1;
}

int b() {
    std::cout << "B" << std::endl;
    return 2;
}

int c() {
    std::cout << "C" << std::endl;
    return 3;
}

int d(int a = a(), int b = b(), int c = c()) {
    return a + b + c;
}

class S {
    
};

template<typename T>
    requires (!std::is_lvalue_reference_v<T>)
void foo(T&& vec) {
    std::cout << "T here" << std::endl;
    for (const auto& val : vec) {
        std::cout << val << std::endl;
    }
}

int main() {

    std::vector obj = {1, 2, 3};
    const std::vector cobj = {1, 2, 3};
    foo(std::move(obj));
    foo(std::move(cobj));
    foo(std::vector{1, 2, 3});
    
    std::cout << d() << std::endl;
    std::cout << Sum(1, 2, 3, 4, 5) << std::endl;


    return 0;
}
