#include <iostream>
#include <string>
#include <memory>


struct Person {
    Person() = default;
    ~Person() = default;

};


int main() {

    std::shared_ptr<Person> sp = std::make_shared<Person>();
    {
        std::shared_ptr<Person> sp1 = sp;
        std::shared_ptr<Person> sp2 = sp;
        std::cout << sp.use_count();    
    }
    std::cout << sp.use_count();

    return 0;

}
