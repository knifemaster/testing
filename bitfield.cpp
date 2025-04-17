#include <iostream>
#include <vector>
#include <string>


struct Data {
    unsigned bf1 : 10;
    int bf2 : 12;

};

int main() {
    std::cout << sizeof(Data) << std::endl;


}
