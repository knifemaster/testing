#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

// Абстрактный класс Наблюдателя
class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void update(const std::string& message) = 0;
};

// Абстрактный класс Субъекта (Observable)
class ISubject {
public:
    virtual ~ISubject() = default;
    virtual void attach(std::shared_ptr<IObserver> observer) = 0;
    virtual void detach(std::shared_ptr<IObserver> observer) = 0;
    virtual void notify() = 0;
};

// Конкретный Субъект
class Subject : public ISubject {
private:
    std::vector<std::shared_ptr<IObserver>> observers;
    std::string state;

public:
    void attach(std::shared_ptr<IObserver> observer) override {
        observers.push_back(observer);
    }

    void detach(std::shared_ptr<IObserver> observer) override {
        observers.erase(
            std::remove(observers.begin(), observers.end(), observer),
            observers.end()
        );
    }

    void notify() override {
        for (const auto& observer : observers) {
            observer->update(state);
        }
    }

    void setState(const std::string& newState) {
        state = newState;
        notify();
    }

    std::string getState() const {
        return state;
    }
};

// Конкретный Наблюдатель
class ConcreteObserver : public IObserver {
private:
    std::string name;

public:
    explicit ConcreteObserver(const std::string& name) : name(name) {}

    void update(const std::string& message) override {
        std::cout << "Observer " << name << " received: " << message << std::endl;
    }
};

// Пример использования
int main() {
    // Создаем субъект
    auto subject = std::make_shared<Subject>();

    // Создаем наблюдателей
    auto observer1 = std::make_shared<ConcreteObserver>("Observer 1");
    auto observer2 = std::make_shared<ConcreteObserver>("Observer 2");
    auto observer3 = std::make_shared<ConcreteObserver>("Observer 3");

    // Подписываем наблюдателей
    subject->attach(observer1);
    subject->attach(observer2);
    subject->attach(observer3);

    // Изменяем состояние субъекта (наблюдатели получат уведомления)
    subject->setState("First state change");

    // Отписываем одного наблюдателя
    subject->detach(observer2);

    // Еще одно изменение состояния
    subject->setState("Second state change");

    return 0;
}


/*
#include <iostream>
#include <vector>
#include <functional>
#include <memory>

class Subject {
private:
    std::vector<std::function<void(const std::string&)>> observers;
    std::string state;

public:
    void attach(const std::function<void(const std::string&)>& observer) {
        observers.push_back(observer);
    }

    void notify() {
        for (const auto& observer : observers) {
            observer(state);
        }
    }

    void setState(const std::string& newState) {
        state = newState;
        notify();
    }
};

int main() {
    Subject subject;

    // Подписываем лямбда-функции как наблюдателей
    auto observer1 = [](const std::string& msg) {
        std::cout << "Observer 1: " << msg << std::endl;
    };

    auto observer2 = [](const std::string& msg) {
        std::cout << "Observer 2: " << msg << std::endl;
    };

    subject.attach(observer1);
    subject.attach(observer2);

    subject.setState("First notification");
    subject.setState("Second notification");

    return 0;
}*/
