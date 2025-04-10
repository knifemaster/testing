#include <iostream>
#include <vector>
#include <list>
#include <chrono>

int main() {
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
        std::cout << "Time ms: " << ms << std::endl;
    }


    return 0;
}
