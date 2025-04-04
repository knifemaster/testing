#include <iostream>

int add(int a, int b) {
    while(b != 0) {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }

    return a;
}

int add_with_pointers(int a, int b) {
    char* p = reinterpret_cast<char*>(a);
    return reinterpret_cast<int>(&p[b]);
}

int main() {

    std::cout << add(50, 15) << std::endl;
    std::cout << add(100, 451) << std::endl;

    std::cout << add_with_pointers(50, 15) << std::endl;
    std::cout << add_with_pointers(100, 451) << std::endl;

}
