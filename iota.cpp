#include <generator>
#include <ranges>
#include <print>

std::generator<int> iota() {
    int x = 0;
    while (true) {
        co_yield x++;
    }

}

std::generator<int> power(int val) {
    int x = 1;
    while(true) {
        co_yield x*=val;
    }
}


int main() {

    for (int i : iota() | std::views::take(10)) {
        std::print("{} ", i);
    }
    std::println();
    for (const auto v : power(2) | std::views::take(10)) {
        std::print("{} ", v);
    }

}

