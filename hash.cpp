#include <iostream>
#include <functional>
#include <string>
#include <unordered_map>


struct Person {
    std::string name;
    int age;

    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }

};


//specialization std::hash for Person

namespace std {
    template<>
    struct hash<Person> {
        size_t operator()(const Person& p) const {
            cout << "Используется std::hash<Person>" << "\n";
            size_t h1 = hash<string>()(p.name);
            size_t h2 = hash<int>()(p.age);
            return h1 ^ (h2 << 1);
        }
    };

}

struct PersonHasher {
    size_t operator()(const Person& p) const {
        std::cout << "Используется PersonHasher" << "\n";
        return hash<string>()(p.name) * 31 + hash<int>()(p.age);
    }
};
