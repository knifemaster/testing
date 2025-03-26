#include <iostream>

struct Data {
    Data(int val): val(val) {
        std::cout << "before construction " << val << "\n";
        throw std::runtime_error("exception");
        
    }

    ~Data() {
        std::cout << val << "\n";
        std::cout << "destructor " << "\n";
    }

    int val;

};


int main(int argc, char** argv) {

    try {
        Data* data = new Data(10);
        delete data;
    } catch (const std::exception& e) {
        std::cout << "error " << e.what() << "\n";
    }
    
    return 0;

}
