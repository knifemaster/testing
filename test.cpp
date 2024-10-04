#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
int main()
{
    int i = 10;

    std::string s = "test";
    std::unordered_set<int> v;
    for (size_t index = 0; index < 10; index++) {
        v.insert(index);
    }
    std::cout << s << i << std::endl;
}
