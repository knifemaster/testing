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



//3. Обёртка для std::thread с перехватом исключений
//Можно создать класс-обёртку, которая автоматически перехватывает исключения:
class ThreadGuard {
    public:
        template<typename Function, typename... Args>
        ThreadGuard(Function&& f, Args&&... args) {
            thread_ = std::thread([this, f = std::forward<Function>(f), args...]() {
                    try {
                        f(args...);
                    }
                    catch (const std::exception& e) {
                        exception_ = std::current_exception();
                    }
                    catch (...) {
                        exception_ = std::current_exception();
                    }
                    });
        }

        ~ThreadGuard() {
            if (thread_.joinable()) {
                thread_.join();
            }
            if (exception_) {
                std::rethrow_exception(exception_);
            }
        }
    private:
        std::thread thread_;
        std::exception_ptr exception_;
};

void risky_task() {
    throw std::runtime_error("Thread crashed!");
}

//Плюсы:
//✅ Автоматический перехват исключений.
//✅ Можно пробросить исключение в главный поток.
//Минусы:
//❌ Нужно создавать обёртку.



//4. Использование std::promise для передачи исключений
//Если поток должен уведомить главный поток об ошибке:
void worker(std::promise<void> promise) {
    try {
        throw std::runtime_error("Error in worker thread!");
        promise.set_value();
    }
    catch (...) {
        promise.set_exception(std::current_exception());
    }
}
//Плюсы:
//✅ Полный контроль над передачей исключений.
//✅ Подходит для сложных сценариев.
//Минусы:
//❌ Больше boilerplate-кода.





int main() {
    // last 4 variant with worker
    std::promise<void> promise;
    auto future4 = promise.get_future();
    std::thread t1(worker, std::move(promise));
    try {
        future4.get();
    }
    catch (const std::exception& e) {
        std::cerr << "Caught: " << e.what() << "\n";
    }
    t1.join();



    std::thread t(thread_function);
    t.join();



    auto future = std::async(std::launch::async, risky_operation);
    try {
        int result = future.get(); // Бросит исключение, если оно было в потоке
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception from thread: " << e.what() << "\n";
    }
    


    try {
        ThreadGuard guard(risky_task);
    }
    catch (const std::exception& e) {
        std::cerr << "Main thread caught :" << e.what() << "\n";
    }

    
    return 0;


}
