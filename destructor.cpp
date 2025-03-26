#include <iostream>
#include <exception>
#include <optional>
#include <memory>

class ForException {
    public:
        ForException(int value) : value(value) {}
        ~ForException() noexcept(false) {
            throw std::exception();
            std::cout << "after exception" << "\n";
        }
    private:
        int value;
};

class S {
    public:
        S() {}
        S(const S& s) {
            std::cout << "S::S(const S&)" << "\n";
        }
        S& operator=(const S& s) {
            std::cout << "S::operator=" << "\n";
            return *this;
        }
        ~S() {
            std::cout << "S::~S()" << "\n";
        }        
};

void f1() {
    S s = S(); // destructor calls
    S* s2 = new S(); // destructor not calls
    
    std::unique_ptr<S> s_uniq = std::make_unique<S>();//destructor calls

    throw "exception";
    delete s2;
}

void f2() {
    f1();
}


int main() {

    try {
        f2();
    } catch(...) {
        std::cerr << "catch from function" << "\n";
    }

    try {
        ForException object(100);
    } catch (const std::exception& e) {
        std::cerr << "exception catched " <<e.what() << "\n";
    }

    int result;
    try {
        int a = 1;
        int b = 0;

        if (b == 0) {
            throw std::runtime_error("Division by zero");
        }

        result = a / b;
    } catch(const std::exception& e) {
        std::cerr << e.what() << "\n";
        result = 0; 
    }

    std::cout <<  "result is " << result << "\n";
    

    return 0;
}
