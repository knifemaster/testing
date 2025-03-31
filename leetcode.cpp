#include <iostream>
#include <vector>
//#include <cstdlib>
//#include <cmath>


/*
int reverse(int x) {
    int number;
    bool is_negative = false;
    if (x < 0) {
        number = std::abs(x);
        is_negative = true;
    }

    int remainder;
    int power = 0;
    int result = 0;

    while(number > 0) {        
        remainder = number % 10;
        std::cout << "num " << number << std::endl;
        number /= 10;
        result += remainder * std::pow(10, power);
        power++; 
    }

    if (is_negative) {
        result = -result;
    }
    return result;

}
*/

std::string converts(std::string s, int num_rows) {
    if (num_rows == 1) return s;
    std::string result;
    int n = s.size();
    int cycle_length = 2 * num_rows - 2;

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j + 1 < n; j+= cycle_length) {
            result += s [j + i];

            if (i != 0 && i != num_rows - 1 && j + cycle_length - 1 < n) {
                result += s[j + cycle_length - i];
            }
        }
    }

    return result;

}


int main() {

    std::string str = "PAYPALISHIRING";
    int rows = 3;

    std::cout << converts(str, rows) << std::endl;;
    
    //int x = 321;    
    //int res = reverse(x);    
    //std::cout << "rev " << res << std::endl;

   // std::vector<int> vi(128, -1);
    
    

    return 0;
}
