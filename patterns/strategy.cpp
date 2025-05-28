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
