#include <vector>
#include <iostream>
#include <iterator>
#include <list>

int main() {

    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto it = vec.begin();
    auto new_it = std::next(it, 2);
    std::cout << *new_it << std::endl;
    std::cout << *it << std::endl;

    std::list<int> lst = {10, 20, 30, 40, 50};
    auto it2 = lst.end();
    auto new_it2 = std::prev(it, 2);
    std::cout << *new_it << std::endl;

    return 0;
}
