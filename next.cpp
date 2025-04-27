#include <vector>
#include <iostream>
#include <iterator>

int main() {

    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto it = vec.begin();
    auto new_it = std::next(it, 2);
    std::cout << *new_it << std::endl;
    std::cout << *it << std::endl;


    return 0;
}
