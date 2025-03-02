#include <iostream>
#include <string>
#include <string_view>
#include <ranges>
#include <vector>


int main() {

	const std::string path = "/path/1/2/hello";

	auto view = path | std::ranges::views::split('/')
			| std::ranges::views::transform([](auto&& rng) {
				return std::string_view(&*rng.begin(), std::ranges::distance(rng));
			});

	for (const auto& token : view) {
		std::cout << token << std::endl;
	}


	std::string name("HE LL O W O RL D");

    	auto split_view = std::ranges::views::split(name, ' ');

    
    	for (const auto& subrange : split_view) {
        	std::cout << std::string_view(subrange.begin(), subrange.end()) << '\n';
    	}




	return 0;
}
