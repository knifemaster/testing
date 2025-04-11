#include <iostream>
#include <exception>
#include <thread>
#include <stdexcept>

void riskyFunction() {
    throw std::runtime_error("Ошибка в riskyFunction!");
}


void handleAndRethrow() {
    try {
        riskyFunction();
    } catch (const std::runtime_error& e) {
        std::cerr << "Логирование исключекния перед повторным выбросом...\n";
        std::cerr << e.what() << "\n";
        throw std::exception();//std::rethrow();
    }
}

void worker(std::exception_ptr& ex_ptr) {
    try {
        throw std::runtime_error("Ошибка в потоке!");
    } catch (...) {
        ex_ptr = std::current_exception();
    }
}


int main() {

    try {
        handleAndRethrow();
    } catch (const std::exception& e) {
        std::cerr << "Поймано исключение: " << e.what() << "\n";
    }

    std::exception_ptr ex_ptr;
    std::thread t(worker, std::ref(ex_ptr));
    t.join();

    if (ex_ptr) {
        try {
            std::rethrow_exception(ex_ptr);
        } catch (const std::exception& e) {
            std::cerr << "Ошибка из потока: "<< e.what() << "\n";
        }
    }

    return 0;
}
