#include <iostream>
#include <algorithm>
#include <vector>

int main() {

    std::vector<int> vi = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto it = vi.begin();

    std::advance(it, 5);
    std::cout << *it;

    return 0;
}
