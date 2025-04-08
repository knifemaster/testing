#include <generator>
#include <ranges>
#include <print>

std::generator<int> iota() {
    int x = 0;
    while (true) {
        co_yield x++;
    }

}

int main() {

    for (int i : iota() | std::views::take(10)) {
        std::print("{ } ", i);
    }

}
