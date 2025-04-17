#include <iostream>
#include <valarray>
#include <cmath>


int main() {
    // Создание valarray
    std::valarray<int> v1 = {1, 2, 3, 4, 5};
    std::valarray<int> v2 = {5, 4, 3, 2, 1};

    // Арифметические операции
    auto sum = v1 + v2;
    auto diff = v1 - v2;
    auto product = v1 * v2;
    auto quotient = v1 / (v2 + 1); // чтобы избежать деления на 0

    for (int i : v1 / v2) {
        std::cout <<  i << ",";
        }


    std::for_each(std::begin(sum), std::end(sum), [amount](Chain & c)
    {
        c+= amount;
    });

    std::cout << "Sum: ";
    for (auto n : sum) std::cout << n << ' ';
    std::cout << "\nProduct: ";
    for (auto n : product) std::cout << n << ' ';

    // Математические функции
    std::valarray<double> v3 = {1.0, 2.0, 3.0, 4.0, 5.0};
    auto sqrt_v = sqrt(v3);
    auto exp_v = exp(v3);

    std::cout << "\nSquare roots: ";
    for (auto n : sqrt_v) std::cout << n << ' ';
}
