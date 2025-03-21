#include <vector>
#include <cmath>
#include <cstdio>
#include <ctime>

using namespace std;

class Solution {
private:
    double radius;      // Радиус круга
    double x_center;    // Координата X центра круга
    double y_center;    // Координата Y центра круга

public:
    // Конструктор класса
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
        srand(time(0));  // Инициализация генератора случайных чисел
    }

    // Метод для генерации случайной точки внутри круга
    vector<double> randPoint() {
        // Генерация случайного угла от 0 до 2π
        double theta = 2 * M_PI * ((double) rand() / RAND_MAX);

        // Генерация случайного радиуса, учитывая равномерное распределение
        double r = sqrt((double) rand() / RAND_MAX) * radius;

        // Преобразование полярных координат в декартовы
        double x = r * cos(theta);
        double y = r * sin(theta);

        // Смещение координат к центру круга
        x += x_center;
        y += y_center;

        // Возврат результата в виде вектора [x, y]
        return {x, y};
    }
};

// Пример использования
int main() {
    Solution solution(1.0, 0.0, 0.0);  // Создание объекта с радиусом 1 и центром в (0, 0)
    vector<double> point = solution.randPoint();  // Генерация случайной точки
    printf("[%f, %f]\n", point[0], point[1]);  // Вывод результата
    return 0;
}
