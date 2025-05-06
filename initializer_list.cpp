#include <iostream>
#include <vector>
#include <initializer_list>


class MyContainer {
    public:
        MyContainer(std::initializer_list<int> list) {
            for (int num : list) {
                data.push_back(num);
            }
        }

        void print() {
            for (int num : data) {
                std::cout << num << " ";
            }

            std::cout << "\n";
        }

    private:
        std::vector<int> data;

};


int main() {

    MyContainer container = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    container.print();

    return 0;
}
