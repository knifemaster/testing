#include <memory_resource>

int main() {
    char buffer[1024];
    std::pmr::monotonic_buffer_resource pool{std::data(buffer), std::size(buffer)};
    std::pmr::vector<int> vec{&pool};

    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }

    for (int x : vec) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
