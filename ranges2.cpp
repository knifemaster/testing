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

    std::print("{}", result);
    std::print("{}", squared);

    return 0;
}
