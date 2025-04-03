#include <atomic>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <iostream>


class MyMutex {
public:
    MyMutex() : locked_(false) {}

    void lock() {
        std::unique_lock<std::mutex> lock(mutex_);
        while (locked_.load(std::memory_order_acquire)) {
            condition_.wait(lock);
        }
        locked_.store(true, std::memory_order_release);
    }

    void unlock() {
        std::unique_lock<std::mutex> lock(mutex_);
        locked_.store(false, std::memory_order_release);
        condition_.notify_one();
    }

private:
    std::atomic<bool> locked_;
    std::mutex mutex_;
    std::condition_variable condition_;
};



MyMutex my_mutex;
int shared_resource = 0;

void thread_function() {
    my_mutex.lock();
    shared_resource++;
    std::cout << "Shared resource: " << shared_resource << std::endl;
    my_mutex.unlock();
}

int main() {
    std::thread t1(thread_function);
    std::thread t2(thread_function);

    t1.join();
    t2.join();

    return 0;
}
