#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <stack>
#include <cmath>
#include <optional>
#include <chrono>
#include <limits>
#include <utility>


class Person {
	public:
		Person(int age, std::string& name) : age(age), name(name) {
			std::cout << "constructor" << std::endl;
		}
	
	//private:
		int age;
		std::string name;


};


int sub_array_sum(std::vector<int>& nums, int k) {
	std::unordered_map<int, int> map_sums;

	map_sums[0] = 1;
	int result = 0;
	int sum = 0; 

	for (const auto& number : nums) {
		sum += number;
		result += map_sums[sum - k];
		map_sums[sum]++;
	}

	return result;
}


int main() {

	std::vector<int> nums {1, 2, 3};
	int k_param = 3;

	std::vector<int> nums2 {1, 1, 1};
	int k2_param = 2;

	int result = sub_array_sum(nums, k_param);
	
	std::cout << "result is " << result << std::endl;
	std::cout << "result is " << sub_array_sum(nums2, k2_param) << std::endl;

	std::string jannet = "jannet";
	std::string Juliet = "juliet";

	auto p_person = std::make_unique<Person>(32, jannet);
	auto p_Juliet = std::make_shared<Person>(23, Juliet);
	auto p_share = p_Juliet;
	std::vector<int> numbers {1, 1, 3, 3, 100, 2, 4, 2, 4};


	int num = numbers[0];
	for (size_t i = 1; i < numbers.size(); ++i) {
		num = num ^ numbers[i];
	
	}

	std::cout << num << std::endl;
	std::cout << p_person->age << std::endl;
	std::cout << p_Juliet.use_count() << std::endl;
	std::cout << p_Juliet.get()->age << std::endl;
	return 0;

}
