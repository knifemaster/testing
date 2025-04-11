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


int main() {

    try {
        handleAndRethrow();
    } catch (const std::exception& e) {
        std::cerr << "Поймано исключение: " << e.what() << "\n";
    }

    return 0;
}
