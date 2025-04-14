#include <future>
#include <iostream>
#include <thread>
#include <chrono>
#include <stdexcept>
#include <numeric>
#include <vector>


void worker(std::promise<int>&& prom, int id) {
    prom.set_value(id * 10);
}

int main() {
    std::promise<int> prom;
    std::shared_future<int> shared_fut = prom.get_future().share();
    
    std::thread worker_thread(worker, std::move(prom), 5);
    
    // Несколько потребителей могут читать результат
    std::future<int> fut1 = std::async([&] { return shared_fut.get() + 1; });
    std::future<int> fut2 = std::async([&] { return shared_fut.get() + 2; });
    
    std::cout << "Результат 1: " << fut1.get() << std::endl;
    std::cout << "Результат 2: " << fut2.get() << std::endl;
    
    worker_thread.join();
    return 0;
}





/*
int worker(int id, int value) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    //std::cout << "id" << id << std::endl;
    std::cout <<"id "<< id << "thr_id :" << std::this_thread::get_id()<<std::endl;;
    return id * value;
}

int main() {
    std::vector<std::future<int>> futures;

    // Запускаем 5 потоков
    for (int i = 0; i < 5; ++i) {
        futures.push_back(std::async(std::launch::async, worker, i, 5));
    }

    // Собираем результаты
    int total = 0;
    for (auto& fut : futures) {
        total += fut.get(); // Блокируется, пока результат не будет готов
    }

    std::cout << "Общий результат: " << total << std::endl;
    return 0;
}

*/



/*
// transfer exception from thread to other thread
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
*/

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
