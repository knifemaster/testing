#include <iostream>
#include <vector>
#include <algorithm>
#include <print>

void reverse(std::vector<int>& v) {
    int l = 0;;
    int r = v.size() - 1;

    while (l < r) {
        std::swap(v[l], v[r]);
        l++;
        r--;
    }
}


int main() {

    std::vector<int> vi = {1, 2, 3, 4, 5, 6, 7, 8};
    std::println("{}", vi);
    reverse(vi);
    std::println("{}", vi);
}
