#include <iostream>
#include <string>
#include <vector>
#include <memory>


class IObserver {
    public:
        virtual ~IObserver() = default;
        virtual void update(const std::string& message) = 0;

}


class ISubject {
    public:
        virtual ~ISubject() = default;
        virtual void attach(std::shared_ptr<IObserver> observer) = 0;
        virtual void detach(std::shared_ptr<IObserver> observer) = 0;
        virtual void notify() = 0;
};


class Subject : public ISubject {
    private:
        std::vector<std::shared_ptr<IObserver>> observers;
        std::string state;

    public:
        void attach(std::shared_ptr<IObserver> observer) override {
            observers.push_back(observer);
        }

        void detach(std::shared_ptr<IObserver> observer) override {
            observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
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
