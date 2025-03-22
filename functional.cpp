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
    std::cout << std::endl;


    std::vector<int> even_numbers;

    auto is_even = [](int n) { return n % 2 == 0; };
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(even_numbers), is_even);

    for (int n : even_numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;


    return 0;
}
