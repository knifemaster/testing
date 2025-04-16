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


    //4. Нарушение strict aliasing (доступ к объекту через указатель несовместимого типа)
    float x = 3.14f;
    int* ptr = (int*)&x;  // UB (если потом разыменовать *ptr)


    //5. Целочисленное переполнение (для знаковых типов)
    int x = INT_MAX;
    x = x + 1;  // UB: переполнение знакового int


    //6. Изменение строкового литерала
    char* str = "hello";  // В C++11 и новее это ошибка, но в C это UB
    str[0] = 'H';         // UB: попытка изменить строковый литерал


    //7. Нарушение порядка вычислений (sequence point violation)
    int i = 0;
    int x = i++ + i++;  // UB: порядок вычислений не определён


    //8. Использование удалённой памяти
    int* ptr = new int(42);
    delete ptr;
    int x = *ptr;  // UB: доступ к удалённой памяти


    //9. Множественное освобождение памяти (double free)
    int* ptr = new int(10);
    delete ptr;
    delete ptr;  // UB: повторное удаление


    //10. Использование memcpy с перекрывающимися областями
    char str[] = "hello";
    memcpy(str + 1, str, 5);  // UB: перекрывающиеся области


    //11. Несоблюдение правил вызова std::launder (в C++17 и новее)
    struct A { int x; };
    A a{10};
    new (&a) A{20};
    int y = a.x;  // UB (без std::launder в некоторых случаях)




    return 0;
}
