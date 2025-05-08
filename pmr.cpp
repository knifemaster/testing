#include <memory_resource>
#include <iostream>

int main() {
    char buffer[1024];
    std::pmr::monotonic_buffer_resource pool{std::data(buffer), std::size(buffer)};
    std::pmr::vector<int> vec{&pool};

    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }

    for (int x : vec) {
        std::cout << x << " ";
    }
    std::cout << "\n";


    std::pmr::synchronized_pool_resource pool_for_string;
    std::pmr::string str{"Hello, PMR!", &pool_for_string};

    std::cout << str << "\n";



    return 0;
}
