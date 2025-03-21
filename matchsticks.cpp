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

    return backtrack(matchsticks, sides, 0, target);

}

bool backtrack(const std::vector<int>& matchsticks, std::vector<int>& sides, int index, int target) {

    if (index == matchsticks.size()) {
        return sides[0] == target && sides[1] == target && sides[2] == target && sides[3] == target;
    }

    for (int i = 0; i < 4; ++i) {
        if (sides[i] + matchsticks[index] <= target) {
            sides[i] += matchsticks[index];

            if (backtrack(matchsticks, sides, index + 1, target)) {
                return true;
            }

            sides[i] -= matchsticks[index];
            if (sides[i] == 0) 
                break;
        }
    }

    return false;
}


