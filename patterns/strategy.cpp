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


int main() {
    PaymentProcessor processor;

   
    processor.setPaymentStrategy(std::make_unique<CreditCardPayment>("1234567890123456", "123"));
    processor.executePayment(1000);

   
    processor.setPaymentStrategy(std::make_unique<PayPalPayment>("user@example.com"));
    processor.executePayment(500);

   
    processor.setPaymentStrategy(std::make_unique<CryptoPayment>("0xABC123DEF456"));
    processor.executePayment(0.1);

    return 0;
}
