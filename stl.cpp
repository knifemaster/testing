#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <list>
#include <array>
#include <string>
#include <algorithm>
#include <queue>
#include <ranges>
#include <bit>
#include <forward_list>
#include <initializer_list>
#include <string_view>


template<class Iter>
void merge_sort(Iter first, Iter last) {
    if (last - first > 1) {
        Iter middle = first + (last - first) / 2;
        merge_sort(first, middle);
        merge_sort(middle, last);
        std::inplace_merge(first, middle, last);
    }

}


auto print_subrange = [](std::ranges::viewable_range auto&& r) {
    std::cout << "[";
    for (int pos{}; auto elem: r)
        std::cout << (pos++ ? " " : "") << elem;
    std::cout << "] ";
};


int main() {

    std::set<int> m_set = {1, 2, 3, 3, 4, 5, 6, 7}; 
    auto it = m_set.find(5);

   // auto lower = std::lower_bound(u_set.begin(), u_set.end(), 5);
   // std::cout << *lower << std::endl;

    std::unordered_set<int> u_set = { 1, 2, 3, 4, 54, 65, 3, 4, 43 };
    
    std::vector<int> vec = { 1, 2, 3, 3, 3, 4, 5, 6, 6 };
    std::set<int> set_int(vec.begin(), vec.end());

    for (auto it = set_int.begin(); it != set_int.end(); it++) {
        std::cout << *it << std::endl;
    }

    const auto data = { 1, 8, 5, 6, 3, 4, 0, 9, 7, 2 };
    
    std::cout << std::endl;

    std::priority_queue<int, std::vector<int>, std::greater<int>> max_priority_queue;

    for (const int n : data) {
        max_priority_queue.push(n);
    }

    for (int i = 0; i < data.size(); i++) {
        max_priority_queue.pop();
        auto value = max_priority_queue.top();
        std::cout << value << std::endl;
    }

    std::deque<int> deq;

    deq.push_front(1);
    deq.push_front(2);
    deq.push_back(4);
    deq.push_back(12);

    deq.pop_front();
    deq.pop_back();
    //std::cout << deq.pop_front() << std::endl;
    //std::cout << deq.pop_back() << std::endl;
    std::cout << std::endl;
    for (const auto& val : deq) {
        std::cout << val << std::endl;
    }

    std::list<std::string> list_fruits;
    list_fruits.push_back("banana");
    list_fruits.push_back("apple");

    //unsigned int x = 0b00000010;
    //unsigned int x = 0b0000000000011111100000000000000000000000;
    //for (unsigned int i = 0; i < 32; i++) {
    //    std::cout << i << " : " << std::has_single_bit(i) << " " << std::bit_width(i) << '\n';
        
    //}
    //std::cout << i << ":" <<std::has_single_bit(x) << '\n';    
    //std::cout << std::bit_width(x) << '\n';
    //std::cout << std::countl_zero(x) << std::endl;
    //std::cout << std::countr_zero(x) << std::endl;
   
    namespace rv = std::ranges::views;
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto result = numbers | rv::filter([](int x) { return x % 2 == 0; }) | rv::transform([](int x) { return x*x ;}) | rv::take(3) | rv::drop(2);
    for (const auto& number : result) {
        std::cout << number << " ";
    }


    for (const unsigned width : std::views::iota(1U, 2U + numbers.size())) {
        auto const chunks = numbers | std::views::chunk(width);
        std::cout << "chunk(" << width << "): ";
        std::ranges::for_each(chunks, print_subrange);
    }

    //auto result2 = numbers | 
    
    std::forward_list<int> fwlist = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    fwlist.assign( {10, 11, 12, 13, 14, 15 } );
    fwlist.clear();
    std::cout << std::endl;
    for (const auto& v : fwlist) {
        std::cout << v << " ";
    }


    std::vector<std::vector<int>> v {{1, 2}, {2, 3}, {3, 4}};
    auto joined = v | std::views::join;
    for (const auto& value : joined) {
        std::cout << value << " ";
    }

    std::vector<std::string> vc = { "a", "b", "c", "d" };
    auto joined_with = vc | std::views::join_with('-');
    

    for (const auto& jc : joined_with) {
        std::cout << jc << std::endl;
    }


    std::vector<int> vec_i = { 1, 2, 3, 4, 5, 6, 7, 8 };
    auto sub = std::views::counted(vec_i.begin(), 5);
    for (const auto& val : sub) {
        std::cout << val << std::endl;
    }

    std::vector<int> v1 { 1, 2, 3, 4 };
    std::vector<char> v2 { 'a','b', 'c', 'd' };

    std::cout << std::endl;
    auto zipped = std::views::zip(v1, v2);
    auto sliding = v1 | std::views::slide(2);
    for (const auto& sub_vec : sliding) {
        for (const auto& number : sub_vec) {
            std::cout << number << " ";
        }
        std::cout << std::endl;
    }
    
    std::vector<int> v3 { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    auto take_while = std::ranges::take_while_view(v3, [](int value) { return value < 8; });
    for (const auto& take : take_while) {
        std::cout << take << " ";
    }
    std::cout << std::endl;

    std::vector<char> v4 {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    auto take_chars = std::ranges::take_while_view(v4, [](char character) { return character != 'd'; });
    for (const auto& character : take_chars) {
        std::cout << character << " ";
    }

    using namespace std::literals;
    const auto string_views = {"Hello"sv, "World", "test", "dog"};

    return 0;

}
