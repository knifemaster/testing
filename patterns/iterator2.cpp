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

        RingIterator& operator++() {
            current_pos++;

            if (current_vec == &top_vec && current_pos >= top_vec.size()) {
                current_vec = &down_vec;
                current_pos = 0;
            }
            else if (current_vec == &down_vec && current_pos >= down_vec.size()) {
                current_vec = &top_vec;
                current_pos = 0;
            }

            if (current_vec == &top_vec && current_pos == 0) {
                is_end = true;
            }

            return *this;
        }

        reference operator*() {
            return (*current_vec)[current_pos];
        }

        bool operator!=(const RingIterator& other) const {
            return is_end != other.is_end ||
                   current_vec != other.current_vec ||
                   current_pos != other.current_pos;
        }

    private:
        std::vector<int>& top_vec;
        std::vector<int>& down_vec;
        std::vector<int>* current_vec;
        size_t current_pos;
        bool is_end = false;
    };


    RingIterator begin() {
        return RingIterator(top, down);
    }

    RingIterator end() {
        return RingIterator(top, down, true);
    }
};


int main() {
    
    Ring ring;

    for (int val : ring) {
        std::cout << val << " ";
    }


    return 0;

}

