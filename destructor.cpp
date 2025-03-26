#include <iostream>
#include <exception>

class ForException {
    public:
        ForException(int value) : value(value) {}
        ~ForException() noexcept(false) {
            throw std::exception();
            std::cout << "after exception" << std::endl;
        }
    private:
        int value;
};


int main() {

    try {
        ForException object(100);
    } catch (const std::exception& e) {
        std::cerr << "exception catched " <<e.what() << std::endl;
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
        std::cerr << e.what() << std::endl;
        result = 0; 
    }

    std::cout <<  "result is " << result << std::endl;
    

    return 0;
}
