#include <iostream>
#include <exception>

//void f() noexcept {
void f() noexcept {
    std::cout << "f()\n";
    //throw;
    throw std::exception();
}

int main() {
    try {
        f();
    } catch (...) {
        std::cout << "catch block" << std::endl;
    }

//    throw;

//    try {
//        throw std::exception();
//    } catch(const std::exception& e) {
    
//        std::cout << "in catch function" << std::endl;
//    }

    std::cout << "EndOfMain" << std::endl;
}
