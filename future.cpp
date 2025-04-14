#include <future>
#include <iostream>


int multiply(int x) {
    return x*x;
}

int main() {

    std::future<int> fut = std::async(&multiply, 10);

    std::cout << fut.get();


    return 0;
}

