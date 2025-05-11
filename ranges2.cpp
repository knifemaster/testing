#include <iostream>
#include <print>
#include <vector>
#include <ranges>
#include <algorithm>
#include <string>
#include <string_view>
#include <deque>

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

    for (auto&& [a, b] : rv::cartesian_product(v5, v6)) {
        std::print("{} {}\n", a, b);
    }

    std::print("{}", result);
    std::print("{}", squared);

    return 0;
}
