#include <atomic>
#include <thread>
#include <iostream>



std::atomic<int> x(0);

void thread_func() {
    x.store(42, std::memory_order_relaxed);

}

std::atomic<int> y(0);
std::atomic<bool> ready(false);

void thread_func2() {
    y.store(42, std::memory_order_relaxed);
    ready.store(true, std::memory_order_release);

}

int main() {

    std::thread t(thread_func);
    int value = x.load(std::memory_order_relaxed);
    t.join();

    std::cout << "Value: " << value << std::endl;

    std::thread t2(thread_func2);
    while (!ready.load(std::memory_order_acquire)) {
        std::cout << "Hello world" << std::endl;        // waiting while ready not true
    }

    int value2 = y.load(std::memory_order_relaxed);
    t2.join();
    std::cout << "Value: " << value2 << std::endl;






    return 0;
}
