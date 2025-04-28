#include <iostream>
#include <memory>
#include <string>

class PaymentStrategy {
public:
    virtual ~PaymentStrategy() = default;
    virtual void pay(float amount) const = 0;
};


class CreditCardPayment : public PaymentStrategy {
private:
    std::string cardNumber;
    std::string cvv;

public:
    CreditCardPayment(const std::string& cardNumber, const std::string& cvv)
        : cardNumber(cardNumber), cvv(cvv) {}

    void pay(float amount) const override {
        std::cout << "Оплата " << amount << " руб. через кредитную карту "
                  << cardNumber.substr(cardNumber.length() - 4) << std::endl;
    }
};


class PayPalPayment : public PaymentStrategy {
private:
    std::string email;

public:
    PayPalPayment(const std::string& email) : email(email) {}

    void pay(float amount) const override {
        std::cout << "Оплата " << amount << " руб. через PayPal (" << email << ")" << std::endl;
    }
};


class CryptoPayment : public PaymentStrategy {
private:
    std::string walletAddress;

public:
    CryptoPayment(const std::string& walletAddress) : walletAddress(walletAddress) {}

    void pay(float amount) const override {
        std::cout << "Оплата " << amount << " руб. в криптовалюте на адрес "
                  << walletAddress << std::endl;
    }
};



class PaymentProcessor {
private:
    std::unique_ptr<PaymentStrategy> strategy;

public:
    void setPaymentStrategy(std::unique_ptr<PaymentStrategy> newStrategy) {
        strategy = std::move(newStrategy);
    }

    void executePayment(float amount) const {
        if (strategy) {
            strategy->pay(amount);
        } else {
            std::cout << "Способ оплаты не выбран!" << std::endl;
        }
    }
};



class ActionStrategy {
public:
    virtual ~ActionStrategy() = default;
    virtual void execute() const = 0;
};


class MoveStrategy : public ActionStrategy {
private:
    std::string direction;
    int speed;

public:
    MoveStrategy(const std::string& dir, int spd) : direction(dir), speed(spd) {}

    void execute() const override {
        std::cout << "Двигаюсь в направлении " << direction 
                  << " со скоростью " << speed << std::endl;
    }
};


class AttackStrategy : public ActionStrategy {
private:
    std::string weapon;
    int damage;

public:
    AttackStrategy(const std::string& wpn, int dmg) : weapon(wpn), damage(dmg) {}

    void execute() const override {
        std::cout << "Атакую с помощью " << weapon 
                  << " и наношу " << damage << " урона!" << std::endl;
    }
};


class DefendStrategy : public ActionStrategy {
private:
    std::string shieldType;
    int blockPower;

public:
    DefendStrategy(const std::string& shield, int block)
        : shieldType(shield), blockPower(block) {}

    void execute() const override {
        std::cout << "Защищаюсь с помощью " << shieldType
                  << " и блокирую " << blockPower << " урона!" << std::endl;
    }
};


class Character {
private:
    std::unique_ptr<ActionStrategy> currentStrategy;
    std::string name;

public:
    Character(const std::string& charName) : name(charName) {}

    void setStrategy(std::unique_ptr<ActionStrategy> strategy) {
        currentStrategy = std::move(strategy);
    }

    void performAction() const {
        std::cout << name << ": ";
        if (currentStrategy) {
            currentStrategy->execute();
        } else {
            std::cout << "Не выбрана стратегия действия!" << std::endl;
        }
    }
};



int main() {
    PaymentProcessor processor;

   
    processor.setPaymentStrategy(std::make_unique<CreditCardPayment>("1234567890123456", "123"));
    processor.executePayment(1000);

   
    processor.setPaymentStrategy(std::make_unique<PayPalPayment>("user@example.com"));
    processor.executePayment(500);

   
    processor.setPaymentStrategy(std::make_unique<CryptoPayment>("0xABC123DEF456"));
    processor.executePayment(0.1);


    Character warrior("Воин");
    Character archer("Лучник");

    
    warrior.setStrategy(std::make_unique<MoveStrategy>("вперед", 5));
    warrior.performAction();

    archer.setStrategy(std::make_unique<AttackStrategy>("лук", 15));
    archer.performAction();

    
    warrior.setStrategy(std::make_unique<DefendStrategy>("щит", 10));
    warrior.performAction();

    warrior.setStrategy(std::make_unique<MoveStrategy>("вперед", 50));
    warrior.performAction();
    warrior.performAction();
    archer.setStrategy(std::make_unique<MoveStrategy>("назад", 3));
    archer.performAction();



    return 0;
}
