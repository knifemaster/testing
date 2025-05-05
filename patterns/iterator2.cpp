#include <iostream>
#include <iterator>
#include <vector>


class Ring {
public:
    std::vector<int> top{9, 9, 9, 9, 9, 9, 9, 9, 9};
    std::vector<int> down{9, 9, 9, 9, 9, 9, 9, 9, 9};

    class RingIterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = int;
        using difference_type = std::ptrdiff_t;
        using pointer = int*;
        using reference = int&;

        RingIterator(std::vector<int>& top, std::vector<int>& down, bool is_end = false)
            : top_vec(top), down_vec(down), is_end(is_end) {
            current_vec = &top_vec;
            current_pos = 0;
        }


int main() {


    return 0;

}

