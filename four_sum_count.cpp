#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <string>
#include <unordered_map>

int four_sum_count(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4) {

	int sum = 0;

	int count = 0;
	for (size_t i = 0; i < nums1.size(); ++i) {
	
		for (size_t j = 0; j < nums2.size(); ++j) {
		
			for (size_t k = 0; k < nums3.size(); ++k) {
			
				sum = 0;
				for (size_t l = 0; l < nums4.size(); ++l) {
					sum = nums1[i] + nums2[j] + nums3[k] + nums4[l];

				if (sum == 0) {
					std::cout << "sum 0 indexes is " << i << " " << j << " " << k << " " << l <<std::endl;
					count++;
				}
				
				
				}
			
			
			}
		
		
		}
	
	}


	return count;
}

int main() {

	std::vector<int> n1 {1, 2};
	std::vector<int> n2 {-2, -1};
	std::vector<int> n3 {-1, 2};
	std::vector<int> n4 {0, 2};

	four_sum_count(n1, n2, n3, n4);


	return 0;

}
