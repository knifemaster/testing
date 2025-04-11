#include <thread>
#include <iostream>
#include <exception>

#include <future>

//Самый простой способ — обернуть код потока в try-catch
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

//  Передача исключения в главный поток через std::future
//  Если нужно передать исключение в главный поток, можно использовать std::async + std::future
int risky_operation() {
    throw std::runtime_error("Oops! something went wrong.");
    return 42;
}
// Плюсы:
//✅ Исключение пробрасывается в главный поток.
//✅ Подходит для задач с возвращаемым значением.

//Минусы:
//❌ Только для std::async (не подходит для std::thread).

int main() {

    std::thread t(thread_function);
    t.join();
    
    auto future = std::async(std::launch::async, risky_operation);

    try {
        int result = future.get(); // Бросит исключение, если оно было в потоке
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception from thread: " << e.what() << "\n";
    }
    
    
    return 0;


}
