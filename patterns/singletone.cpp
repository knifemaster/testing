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

    Singleton* singleton = getInstance();

    singleton-> someMethod 



    return 0;
}
