#include <iostream>

int main() {
   
    //1. Выход за границы массива 
    int arr[3] = {1, 2, 3};
    int x = arr[5];  // UB: чтение за пределами массива
    arr[10] = 42;    // UB: запись за пределами массива
    std::cout << x << std::endl;

    
    //2. Разыменование нулевого указателя
    int* ptr = nullptr;
    int x2 = *ptr;  // UB: разыменование nullptr


    //3. Использование неинициализированной переменной
    int x;
    int y = x + 5;  // UB: x не инициализирована


    return 0;
}
