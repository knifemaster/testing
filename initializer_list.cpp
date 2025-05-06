#include <iostream>
#include <vector>
#include <initializer_list>

template<typename T>
class MyContainer {
    public:
        MyContainer(std::initializer_list<T> list) {
            for (const T& num : list) {
                data.push_back(num);
            }
        }

        void print() {
            for (T& num : data) {
                std::cout << num << " ";
            }

            std::cout << "\n";
        }

    private:
        std::vector<T> data;

};


int main() {

    MyContainer<int> container = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    container.print();

    return 0;
}
