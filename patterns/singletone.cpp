#include <iostream>
#include <string>


class Singleton {
private:
    static Singleton* instance;  // Указатель на единственный экземпляр
    Singleton() {}                // Приватный конструктор
    Singleton(const Singleton&) = delete;             // Запрещаем копирование
    Singleton& operator=(const Singleton&) = delete;  // Запрещаем присваивание

public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void someMethod() {
        
        std::cout << "some operation" << "\n";
    }
};

// Инициализация статического члена
Singleton* Singleton::instance = nullptr;

int main() {

    Singleton* singleton1 = Singleton::getInstance();
    Singleton* singleton2 = Singleton::getInstance();

    // Проверяем, что это один и тот же объект
    std::cout << "singleton1 адрес: " << singleton1 << std::endl;
    std::cout << "singleton2 адрес: " << singleton2 << std::endl;

    // Вызываем метод
    singleton1->someMethod();
 

    //singleton->someMethod();



    return 0;
}
