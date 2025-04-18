#include <iostream>
#include <memory>
#include <string>


class Product {
    public:
        virtual ~Product() = default;
        virtual void Use = 0;

};


class ConcreteProductA : public Product {
    public:
        void Use() override {
            std::cout << "Используется продукт А" << "\n";
        }
};
