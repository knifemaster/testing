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


std::atomic<int> a(0);
std::atomic<int> b(0);

void thread_func3() {
    a.store(1, std::memory_order_seq_cst);
    b.store(1, std::memory_order_seq_cst);
}

void thread_func4() {
    while (b.load(std::memory_order_seq_cst) != 1) {
        std::cout << "waiting while b set to 1"<< std::endl;
    }
    int value = a.load(std::memory_order_seq_cst);
    std::cout << "Value: " << value << std::endl;
}


std::atomic<int> z(0);

void thread_func5() {
    int expected = 0;
    while (!z.compare_exchange_weak(expected, 42, std::memory_order_acq_rel)) {
        std::cout <<"keep trying" << std::endl;
    }
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


    std::thread t3(thread_func3);
    std::thread t4(thread_func4);
    t3.join();
    t4.join();


    std::thread t5(thread_func5);
    t5.join();
    int val = z.load(std::memory_order_acquire);
    std::cout << "Value: " << val << std::endl;

   
    return 0;
}
