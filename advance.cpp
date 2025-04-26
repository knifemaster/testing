#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
int main() {

    std::vector<int> vec_i = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    auto it = vec_i.begin();
    std::advance(it, 5);
    std::cout << *it;


    std::set<int> set_i = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    auto set_it = set_i.begin();
    std::advance(set_it, 9);
    std::cout << *set_it << std::endl;



    return 0;
}
