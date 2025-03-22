#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void print_sum(int a, int b, int c) {
    std::cout << "Sum: " << a + b + c << std::endl;
}

class MyClass {
    public:
        void print_value(int x) const {
            std::cout << "Value : " << x << std::endl;
        }
};

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int main() {

    std::vector<int> numbers = {1, 2, 3, 4, 5};

    auto print = [](int n) { std::cout << n << " ";};
    std::for_each(numbers.begin(), numbers.end(), print);

    
    std::function<int(int, int)> add = [](int a, int b) { return a + b;};
    int result = add(3, 4);
    std::cout << "Result: " << result << std::endl;


    auto square = [](int n) { return n * n; };
    std::vector<int> squared(numbers.size());
    std::transform(numbers.begin(), numbers.end(), squared.begin(), square);
    
    for (int n : squared) {
        std::cout << n << " ";
    }
    std::cout << std::endl;


    std::vector<int> even_numbers;

    auto is_even = [](int n) { return n % 2 == 0; };
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(even_numbers), is_even);

    for (int n : even_numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;


    auto double_value = [](int n) { return n * 2; };
    auto add_ten = [](int n) { return n + 10; };
    auto composed_function = [&add_ten, &double_value](int n) {
        return add_ten(double_value(n)); 
    };

    int result_composed = composed_function(5);
    std::cout << "Result: " << result_composed << std::endl;


    auto bound_function = std::bind(print_sum, 10, std::placeholders::_1, 20);
    bound_function(30);


    std::vector<MyClass> objects = { MyClass(), MyClass(), MyClass() };
    auto print_method = std::mem_fn(&MyClass::print_value);
    for (const auto& obj : objects) {
        print_method(obj, 42);
    }


    auto composed_function_two = std::bind(multiply, std::bind(add, std::placeholders::_1, 2), 3);
    int result_composed_two = composed_function(4); // (4 + 2) * 3 = 18
    std::cout << "Result: " << result_composed_two << std::endl;


    return 0;
}
