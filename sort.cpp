#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <functional>


template<typename T>
struct SortPredicate
{
    // Счетчик (внутреннее состояние)
    uint64_t count;
    
    // Инициализация счетчика
    SortPredicate() : count(0) {}
    
    bool operator()(T a, T b) {
        // Подсчет операций сравнения
        ++count; 
        return a < b;
    }
};

int main(int argc, char** argv)
{
    std::vector<int> v = {7,3,8,5,4,6,1,9,2};
    
    // Создаем функтор-предикат, который считает "сравнения"
    SortPredicate<int> p;
    
    // Используем std::ref, чтобы передать функтор по ссылке, а не по значению
    std::sort(v.begin(), v.end(), std::ref(p));
    // Вывод на экран количества сравнений (получилось 28)
    std::cout << p.count << std::endl;
    return 0;
}
