#include <iostream>
#include <vector>
#include <initializer_list>

template<typename T>
class MyContainer {
    public:
        MyContainer(std::initializer_list<T> list) noexcept {
            data.reserve(list.size());
            for (const T& num : list) {
                data.emplace_back(num);
            }
        }

        void print() {
            for (const T& num : data) {
                std::cout << num << " ";
            }

            std::cout << "\n";
        }

    private:
        std::vector<T> data;

};


int sum(std::initializer_list<int> nums) {
    int total = 0;
    for (int num : nums) {
        total += num;
    }
    return total;
}


int main() {

    MyContainer<int> container = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    container.print();

    MyContainer<double> container2 = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    container2.print();

    std::cout << sum({1, 2, 3, 4}) << "\n";
    std::cout << sum({10, 20, 30}) << "\n";


    return 0;
}
