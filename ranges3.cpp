#include <iostream>
#include <vector>
#include <ranges>
#include <string>
#include <format>
#include <print>

struct Person {
    std::string name;
    int age;
};

int main() {

    std::vector<Person> people = {{"Alice", 30}, {"Bob", 25}};

    //std::print("{}", people);

    auto modified_people = people
        | std::views::transform([](Person& p) {
            p.name += " Hello";
            p.age += 20;
            return p;
        });

    auto people_str = modified_people
        | std::views::transform([](const Person& p) {
            return std::format("{} : ({}) ", p.name, p.age);
                })
        | std::views::join
        | std::ranges::to<std::string>();

    auto filtered_people = people
        | std::views::filter([](const Person& p) {
            return p.age % 10 == 0;
                });

    for (const auto& person : filtered_people) {
        std::print("{}", person);
    }
    std::cout << people_str << "\n";

    return 0;
}
