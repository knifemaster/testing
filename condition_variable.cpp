#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

std::mutex mtx;
std::condition_variable cv;
int target_thread_id = 0;  // 0 = ждём ввода, 1/2/3 = пробуждаем поток
bool running = true;       // Флаг для корректного завершения

// Функция потока (ждёт своего ID)
void threadFunction(int thread_id) {
    std::unique_lock<std::mutex> lock(mtx);
    while (running) {
        // Ждём, пока target_thread_id не совпадёт с thread_id
        cv.wait(lock, [thread_id] { 
            return target_thread_id == thread_id || !running; 
        });

        if (!running) break;  // Завершаем, если running = false

        std::cout << "Поток " << thread_id << " разбужен!\n";
        target_thread_id = 0;  // Сбрасываем, чтобы можно было ввести новое число
        cv.notify_all();      // Даём main() продолжить ввод
    }
    std::cout << "Поток " << thread_id << " завершён.\n";
}

int main() {
    std::vector<std::thread> threads;

    // Запускаем 3 потока
    for (int i = 1; i <= 3; ++i) {
        threads.emplace_back(threadFunction, i);
    }

    // Основной цикл ввода
    while (running) {
        int input;
        std::cout << "\nВведите число (1, 2, 3) или 0 для выхода: ";
        std::cin >> input;

        if (input == 0) {
            running = false;  // Завершаем все потоки
            cv.notify_all(); // Разбудим их для выхода
            break;
        } 
        else if (input >= 1 && input <= 3) {
            std::unique_lock<std::mutex> lock(mtx);
            target_thread_id = input;  // Указываем, какой поток разбудить
            cv.notify_all();           // Пробуждаем все потоки

            // Ждём, пока поток не обработает сигнал
            cv.wait(lock, [] { return target_thread_id == 0; });
        } 
        else {
            std::cout << "Ошибка: введите 1, 2, 3 или 0.\n";
        }
    }

    // Ожидаем завершения всех потоков
    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Программа завершена.\n";
    return 0;
}


/*
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

std::mutex mtx;
std::condition_variable cv;
int target_thread_id = 0; // Какой поток нужно разбудить (1, 2 или 3)

// Функция, которую выполняют потоки
void threadFunction(int thread_id) {
    std::unique_lock<std::mutex> lock(mtx);
    
    // Ждём, пока не будет совпадения target_thread_id
    cv.wait(lock, [thread_id] { 
        return target_thread_id == thread_id || target_thread_id == -1; 
    });

    if (target_thread_id == -1) {
        std::cout << "Поток " << thread_id << " завершается (введено не 1, 2 или 3)\n";
    } else {
        std::cout << "Поток " << thread_id << " разбужен!\n";
    }
}

int main() {
    std::vector<std::thread> threads;

    // Запускаем 3 потока
    for (int i = 1; i <= 3; ++i) {
        threads.emplace_back(threadFunction, i);
    }

    // Основной поток ждёт ввода пользователя
    std::cout << "Введите число (1, 2 или 3) для пробуждения потока: ";
    int input;
    std::cin >> input;

    {
        std::lock_guard<std::mutex> lock(mtx);
        if (input >= 1 && input <= 3) {
            target_thread_id = input; // Указываем, какой поток разбудить
        } else {
            target_thread_id = -1; // Если введено не 1, 2 или 3 — завершаем все потоки
        }
    }

    cv.notify_all(); // Пробуждаем все потоки (но продолжится только один)

    // Ждём завершения всех потоков
    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
*/

/*
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>


std::mutex mtx;
std::condition_variable cv;
bool keyPressed = false;


void waitForEnter() {
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "Поток ждет нажатия Enter...\n";

    cv.wait(lock, [] { return keyPressed;});

    std::cout << "Поток получил уведомление и продолжает работу!\n";

}

int main() {

    std::thread worker(waitForEnter);

    std::cout << "Нажмите Enterб чтобы разблокировать поток...\n";
    std::cin.get();
    {
        std::lock_guard<std::mutex> lock(mtx);
        keyPressed = true;
    
    }
    cv.notify_one();

    worker.join();

    return 0;
}
*/
