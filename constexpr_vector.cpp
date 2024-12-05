#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

int main() {
	//constexpr std::vector vi {1, 2, 3, 4, 5, 6, 7};
	
	//constexpr std::sort(vi.begin(), vi.end());
	
	constexpr std::array<int, 4> arra_ints {1, 2, 3, 4};

	std::sort(arra_ints.begin(), arra_ints.end());

	for (const auto& num : arra_ints) {
		std::cout << num << std::endl;
	}


}
