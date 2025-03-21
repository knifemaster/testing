#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


bool makesquare(std::vector<int>& matchsticks) {
    if (matchsticks.empty()) 
        return false;

    int total_length = std::accumulate(matchsticks.begin(), matchsticks.end(), 0);

    if (total_length % 4 != 0) 
        return false;

    int target = total_length / 4;

    std::sort(matchsticks.rbegin(), matchsticks.rend());

    std::vector<int> sides(4, 0);



}
