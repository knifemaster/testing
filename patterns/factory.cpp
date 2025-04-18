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

class IPhone : public Phone {
public:
    std::string Operation() const override {
        return "Создаем модель IPhone";
    }
};

// Класс Creator (создатель) - абстрактная фабрика
class Creator {
public:
    virtual ~Creator() = default;
    virtual std::unique_ptr<Product> FactoryMethod() const = 0;
    
    std::string SomeOperation() const {
        // Вызываем фабричный метод для создания объекта Product
        std::unique_ptr<Phone> phone = this->FactoryMethod();
        // Используем телефон
        std::string result = "Creator: Тот же код создателя работает с " + phone->Operation();
        return result;
    }
};



int main() {
    
    auto productA = Factory::CreateProduct(Factory::PRODUCT_A);
    productA -> Use();

    auto productB = Factory::CreateProduct(Factory::PRODUCT_B);
    productB -> Use();

    return 0;
}
