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
