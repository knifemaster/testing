// compile with
//g++ -ggdb -std=c++23 stack_trace.cpp -lstdc++_libbacktrace

#include <stacktrace>
#include <string>
#include <iostream>

void print_function(int a, std::string& s) {
    auto trace = std::stacktrace::current();
    std::cout << a << s << std::endl;

    std::cout << std::to_string(trace) << std::endl;

}

struct Stack {
    Stack() {
        auto trace = std::stacktrace::current();
        std::cout << std::to_string(trace) << std::endl;
    }
};

void f() {
    Stack st;    
}

void g() {
    f();    
}

int main() {
        std::string s = "Hello world";
        auto trace = std::stacktrace::current();
        std::cout << std::to_string(trace) << std::endl;
        print_function(23, s);

        Stack stack;

        f();

}
