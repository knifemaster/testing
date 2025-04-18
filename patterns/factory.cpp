#include <iostream>
#include <memory>
#include <string>


class Product {
    public:
        virtual ~Product() = default;
        virtual void Use() = 0;

};


class ConcreteProductA : public Product {
    public:
        void Use() override {
            std::cout << "Используется продукт А" << "\n";
        }
};

class ConcreteProductB : public Product {
    public:
        void Use() override {
            std::cout << "Используется продукт B" << "\n";
        }
};


class Factory {
    public:
        enum ProductType {
            PRODUCT_A,
            PRODUCT_B
        };

        static std::unique_ptr<Product> CreateProduct(ProductType type) {
            switch (type) {
                case PRODUCT_A:
                    return std::make_unique<ConcreteProductA>();
                case PRODUCT_B:
                    return std::make_unique<ConcreteProductB>();
                default:
                    throw std::invalid_argument("Неизвестный тип продукта");
            }
        
        }

};


class Phone {
public:
    virtual ~Product() = default;
    virtual std::string Operation() const = 0;
};

class Samsung : public Phone {
public:
    std::string Operation() const override {
        return "Создаем модель Samsung";
    }
};



int main() {
    
    auto productA = Factory::CreateProduct(Factory::PRODUCT_A);
    productA -> Use();

    auto productB = Factory::CreateProduct(Factory::PRODUCT_B);
    productB -> Use();

    return 0;
}
