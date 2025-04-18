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
    virtual ~Phone() = default;
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
    virtual std::unique_ptr<Phone> FactoryMethod() const = 0;
    
    std::string SomeOperation() const {
        // Вызываем фабричный метод для создания объекта Product
        std::unique_ptr<Phone> phone = this->FactoryMethod();
        // Используем телефон
        std::string result = "Creator: Тот же код создателя работает с " + phone->Operation();
        return result;
    }
};

// Конкретные создатели переопределяют фабричный метод
class SamsungCreator : public Creator {
public:
    std::unique_ptr<Phone> FactoryMethod() const override {
        return std::make_unique<Samsung>();
    }
};

class IPhoneCreator : public Creator {
public:
    std::unique_ptr<Phone> FactoryMethod() const override {
        return std::make_unique<IPhone>();
    }
};


// Клиентский код
void ClientCode(const Creator& creator) {
    std::cout << "Клиент: Я не знаю класс создателя, но он все еще работает.\n"
              << creator.SomeOperation() << std::endl;
}


int main() {
    
    auto productA = Factory::CreateProduct(Factory::PRODUCT_A);
    productA -> Use();

    auto productB = Factory::CreateProduct(Factory::PRODUCT_B);
    productB -> Use();


    std::cout << "Приложение запущено с SamsungCreator.\n";
    std::unique_ptr<Creator> creator = std::make_unique<SamsungCreator>();
    ClientCode(*creator);

    std::cout << "\n";

    std::cout << "Приложение запущено с IPhoneCreatorB.\n";
    creator = std::make_unique<IPhoneCreator>();
    ClientCode(*creator);


    return 0;
}
