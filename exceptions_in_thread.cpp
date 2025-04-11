#include <thread>
#include <iostream>
#include <exception>


void thread_function() {
    try {
        throw std::exception();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception in thread: " << e.what() << "\n";
    }
    catch (...) {
        std::cerr << "Unknown exception in thread!" << "\n";
    }
}

int main() {

    std::thread t(thread_function);
    t.join();
    return 0;
}
