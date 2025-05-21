#include <iostream>
#include <print>
#include <vector>
#include <ranges>
#include <algorithm>
#include <string>
#include <string_view>
#include <deque>
#include <sstream>


int main() {

    std::vector<std::string> vs = {"hello", "world", "the", "c++", "best"};

    namespace rv = std::ranges::views;

    auto result = vs | std::views::join | std::ranges::to<std::string>();

    //std::string res = vs | rv::join("-") | std::ranges::to<std::string>();
    
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::deque<int> squared = numbers | rv::transform([](int n) { return n*n;}) | std::ranges::to<std::deque>();

    std::vector<int> v1 {0, 1};
    std::vector<int> v2 {2, 3};

    for (auto&& [a, b] : rv::cartesian_product(v1, v2)) {
        std::print("{} {}\n", a, b);
    }

    std::vector<char> v3 {'a', 'b', 'c'};
    std::vector<char> v4 {'d', 'e', 'f', 'g'};

    for (auto&& [a, b] : rv::cartesian_product(v3, v4)) {
        std::print("{} {}\n", a, b);
    }

    std::string v5 = "abc";
    std::string v6 = "def";
    std::string v7 = "hij";
    std::string v8 = "klm";
    for (auto&& [a, b, c, d] : rv::cartesian_product(v5, v6, v7, v8)) {
        std::print("{} {} {}\n", a, b, c);
    }

    auto st = rv::cartesian_product(v5, v6);

    std::println("{}", result);
    std::println("{}", squared);

    std::vector nums = {1, 2, 3, 4, 5};
    for (auto [a, b] : nums | std::views::pairwise) {
        std::cout << "(" << a << ", " << b << ") ";
    }

    std::println("plus {}", nums | std::views::pairwise_transform(std::plus()));

    std::println("minus {}", nums | std::views::pairwise_transform(std::minus()));

    std::println("multiply {}", nums | std::views::pairwise_transform(std::multiplies()));


    for (const auto& val : st) {
        std::println("{}", val);
    }

    std::vector<int> numbrz = {1, 2, 3, 4, 5};
    auto joined = numbrz
        | std::views::transform([](int x) { return std::to_string(x); })
        | std::views::join
        | std::ranges::to<std::string>();

    std::cout << joined << std::endl;

    return 0;
}
