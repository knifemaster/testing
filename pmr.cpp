#include <memory_resource>
#include <iostream>
#include <map>
#include <set>


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



    std::pmr::unsynchronized_pool_resource pool_for_map;
    std::pmr::map<int, std::pmr::string> my_map{&pool_for_map};
    my_map[1] = "One";
    my_map[2] = "Two";

    for (const auto& [key, val] : my_map) {
        std::cout << key << ": " << val << "\n";
    }


    char set_buffer[1024];
    std::pmr::monotonic_buffer_resource pool_for_set{std::data(set_buffer), std::size(set_buffer)};
    std::pmr::set<int> my_set{&pool_for_set};
    my_set.insert(1);
    my_set.insert(2);
    my_set.insert(3);

    for (const auto& val : my_set) {
        std::cout << val << " ";
    }


    return 0;
}
