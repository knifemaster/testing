#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>



int findRadius(std::vector<int>& houses, std::vector<int>& heaters) {
    std::sort(heaters.begin(), heaters.end());
    int min_radius = 0;

    for (int house : houses) {
    
        auto it = std::lower_bound(heaters.begin(), heaters.end(), house);
        int distance = INT_MAX;

        if (it != heaters.end()) {
            distance = *it - house;
        }

        if (it != heaters.begin()) {
            distance = std::min(distance, house - *(it - 1));
        }

        min_radius = std::max(min_radius, distance);
    
    }

    return min_radius;

}


int main() {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> data = {
        {{1, 2, 3}, {2}},          
        {{1, 2, 3, 4}, {1, 4}},    
        {{1, 5}, {2}},             
        {{1, 2, 3, 4, 5}, {3}},    
        {{1, 1, 1, 1}, {1}},       
        {{1, 3, 5, 7}, {2, 6}}, 
        {{1, 2, 3}, {1, 3}}, 
        {{1, 5, 10}, {2, 8}} 
    };
    
    for (size_t i = 0; i < data.size(); ++i) {
        std::vector<int> houses = data[i].first;
        std::vector<int> heaters = data[i].second;
        
        int radius = findRadius(houses, heaters);
        
        std::cout << "Pairs " << i + 1 << ":\n";
        std::cout << "Houses: [";
        for (size_t j = 0; j < houses.size(); ++j) {
            std::cout << houses[j];
            if (j != houses.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";
        
        std::cout << "Heaters: [";
        for (size_t j = 0; j < heaters.size(); ++j) {
            std::cout << heaters[j];
            if (j != heaters.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";
        
        std::cout << "Minimum radius required: " << radius << "\n\n";
    }
    
    return 0;
}
