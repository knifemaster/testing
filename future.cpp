#include <future>
#include <iostream>
#include <thread>
#include <chrono>
#include <stdexcept>



void worker(std::promise<int> prom) {
    try {
        throw std::runtime_error("Ошибка в рабочем потоке");
        prom.set_value(42);
    } catch(...) {
        prom.set_exception(std::current_exception());
    }
}

int main() {
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();

    std::thread t(worker, std::move(prom));

    try {
        std::cout << "Результат: " << fut.get() << std::endl;
    } catch(const std::exception& e) {
        std::cout << "Поймано исключение: " << e.what() << std::endl;
    }

    t.join();
    return 0;
}


/*
void worker(std::promise<void> prom) {
    std::cout << "Рабочий поток начал работу\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    prom.set_value();
    std::cout << "Рабочий поток завершил работу\n";
}


int main() {
    std::promise<void> prom;
    std::future<void> fut = prom.get_future();

    std::thread t(worker, std::move(prom));
    fut.wait();
    std::cout << "Основной поток получил уведомление\n";

    t.join();
    return 0;

}
*/

/*
int multiply(int x) {
    return x*x;
}

void worker(std::promise<int> prom) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    prom.set_value(42);
}



int main() {

    std::promise<int> prom;
    std::future<int> fut = prom.get_future();
    std::thread t(worker, std::move(prom));

    std::cout << "Результат: " << fut.get() << "\n";

    t.join();


    //std::future<int> fut = std::async(&multiply, 10);
    //std::cout << fut.get();


    return 0;
}
*/
