#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <boost/pool/pool_alloc.hpp>


void standart_allocation() {
    const int N = 10000000;

    while (true) {
        auto start = std::chrono::high_resolution_clock::now();
        {
            std::list<int> list;
            for (int i = 0; i < N; ++i) {
                list.emplace_back(i);
            }
        }
        auto end = std::chrono::high_resolution_clock::now();

        double ms = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << "Time ms : " << ms << std::endl;
    }

}

void boost_allocation() {
    const int N = 10000000;

    while (true) {
        auto start = std::chrono::high_resolution_clock::now();
        {
            // slow because uses mutexes
            //std::list<int, boost::fast_pool_allocator<int>> list;
            
            std::list<int, boost::fast_pool_allocator<int, boost::default_user_allocator_new_delete, boost::details::pool::null_mutex>> list;
            for (int i = 0; i < N; ++i) {
                list.emplace_back(i);
            }   
        }
        auto end = std::chrono::high_resolution_clock::now();
        double ms = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << "Time ms : " << ms << std::endl;

    }

}


int main() {

    boost_allocation();

    return 0;
}
