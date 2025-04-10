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

template <class T>
class allocator {
    public:

        using value_type = T;

        T* allocate(size_t n) {
            std::cout << "Items : " << n << " allocate: " << n * sizeof(T) << "bytes " << std::endl;
            return static_cast<T*>(::operator new(n * sizeof(T)));
        }
        void deallocate(T* ptr, size_t n) {
            std::cout << "Deallocate: " << n * sizeof(T) << "bytes "<< std::endl;
            ::operator delete(ptr);
        }
};

int main() {

    std::vector<int, allocator<int>> vec;
    vec.reserve(100);
    vec.emplace_back(1);
    vec.emplace_back(2);
    vec.emplace_back(3);
    vec.emplace_back(199);

    for (const auto& val : vec) {
        std::cout << val << std::endl;
    }

    //boost_allocation();

    return 0;
}
