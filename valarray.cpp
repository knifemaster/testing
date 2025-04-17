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


#include <iostream>
#include <valarray>

int main() {
    std::valarray<int> va1 = {1, 2, 3, 4, 5};
    std::valarray<int> va2 = {10, 20, 30, 40, 50};

    // Сложение двух valarray
    std::valarray<int> sum = va1 + va2;

    // Умножение на скаляр
    std::valarray<int> scaled = 2 * va1;

    // Математические операции (например, возведение в квадрат)
    std::valarray<int> squared = va1 * va1;

    // Вывод результатов
    std::cout << "Sum: ";
    for (int x : sum) std::cout << x << " ";
    std::cout << "\nScaled: ";
    for (int x : scaled) std::cout << x << " ";
    std::cout << "\nSquared: ";
    for (int x : squared) std::cout << x << " ";

    return 0;
}


#include <iostream>
#include <valarray>
#include <cmath>

int main() {
    std::valarray<double> vals = {1.0, 2.0, 3.0, 4.0, 5.0};

    // Применение функции sqrt к каждому элементу
    std::valarray<double> sqrt_vals = std::sqrt(vals);

    // Логарифмирование
    std::valarray<double> log_vals = std::log(vals);

    std::cout << "Square roots: ";
    for (double x : sqrt_vals) std::cout << x << " ";

    std::cout << "\nLogarithms: ";
    for (double x : log_vals) std::cout << x << " ";

    return 0;
}



#include <iostream>
#include <valarray>

int main() {
    std::valarray<int> data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Использование среза (start, size, stride)
    std::valarray<int> slice = data[std::slice(1, 5, 2)]; // Элементы 1, 3, 5, 7, 9

    // Использование маски
    std::valarray<bool> mask = {true, false, true, false, true};
    std::valarray<int> masked = data[mask]; // Выбирает элементы, где mask == true

    std::cout << "Slice: ";
    for (int x : slice) std::cout << x << " ";

    std::cout << "\nMasked: ";
    for (int x : masked) std::cout << x << " ";

    return 0;
}
