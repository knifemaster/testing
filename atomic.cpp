#include <atomic>
#include <thread>
#include <iostream>



std::atomic<int> x(0);

void thread_func() {
    x.store(42, std::memory_order_relaxed);

}

int main() {

    std::thread t(thread_func);
    int value = x.load(std::memory_order_relaxed);
    t.join();

    std::cout << "Value: " << value << std::endl;

    return 0;
}
