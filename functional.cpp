#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {

    std::vector<int> numbers = {1, 2, 3, 4, 5};

    auto print = [](int n) { std::cout << n << " ";};
    std::for_each(numbers.begin(), numbers.end(), print);

    
    std::function<int(int, int)> add = [](int a, int b) { return a + b;};
    int result = add(3, 4);
    std::cout << "Result: " << result << std::endl;


    auto square = [](int n) { return n * n; };
    std::vector<int> squared(numbers.size());
    std::transform(numbers.begin(), numbers.end(), squared.begin(), square);
    
    for (int n : squared) {
        std::cout << n << " ";
    }



    return 0;
}
