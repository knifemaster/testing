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


size_t customStringHash(const std::string& s) {
    size_t hash = 8381;
    for (char c : s) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}


void demonstrateHashes() {
    std::string text = "Hello";
    Person p{"Alice", 30};

    // standart hashes
    cout << "Хеш строки \"Hello\" (std::hash): " << std::hash<std::string>()(text) << endl;
    cout << "Хеш строки \"Hello\" (custom):    " << customStringHash(text) << endl;

    // custom user hashes
    cout << "Хеш Person (std::hash): " << std::hash<Person>()(p) << endl;
    cout << "Хеш Person (PersonHasher): " << PersonHasher()(p) << endl;
}


void demonstrateHashMaps() {
    Person p1{"Alice", 30};
    Person p2{"Bob", 25};

    cout << "\n1. HashMap со стандартным std::hash<Person>:" << endl;
    std::unordered_map<Person, std::string> stdMap;
    stdMap[p1] = "Developer";
    stdMap[p2] = "Designer";

    for (const auto& pair : stdMap) {
        cout << pair.first.name << ": " << pair.second << endl;
    }

    cout << "\n2. HashMap с кастомным PersonHasher:" << endl;
    std::unordered_map<Person, std::string, PersonHasher> customMap;
    customMap[p1] = "Engineer";
    customMap[p2] = "Architect";

    for (const auto& pair : customMap) {
        cout << pair.first.name << ": " << pair.second << endl;
    }
}
