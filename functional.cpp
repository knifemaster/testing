#include <iostream>
#include <vector>
#include <algorithm>


int main() {

    std::vector<int> numbers = {1, 2, 3, 4, 5};

    auto print = [](int n) { std::cout << n << " ";};
    std::for_each(numbers.begin(), numbers.end(), print);

    return 0;
}
