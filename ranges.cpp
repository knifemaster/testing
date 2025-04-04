#include <iostream>
#include <string>
#include <string_view>
#include <ranges>
#include <vector>
#include <algorithm>
#include <unordered_map>

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



	std::string words("Hello world good evening");
	auto splitted_words = words | std::ranges::views::split(' ');

	for (const auto& word : splitted_words) {
		//std::cout << std::string_view(word.begin(), word.end()) << '\n';
		std::string w(word.begin(), word.end());
		std::cout << w << '\t';
	}



	std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8};
	auto result = numbers | std::views::filter([](int x) {return x % 2 == 0;}) | std::views::transform([](int x){ return x*x;});
	for (const int& number : result) {
		std::cout << number << '\n';
	}



	std::vector<int> data = {10, 20, 30, 40, 50, 60, 70};
	auto first_five_elements = data | std::views::take(5) | std::views::transform([](int x){ return x*10;});

	for (const int& number : first_five_elements) {
		std::cout << number << '\t';
	}
	std::cout << '\n';


	
	std::vector<int> data_for_drop = {11, 22, 33, 44, 55, 66, 77, 88};
	auto skipped_data = data_for_drop | std::views::drop(3);

	for (const int& number : skipped_data) {
		std::cout << number << '\t';
	}
	std::cout << '\n';


	
	std::string text = "Hello world Hello WORLD";
	auto reversed = text | std::views::reverse;

	std::cout << "reversed text";
	for (char character : reversed) {
		std::cout << character << "  ";
	}



	auto sequence = std::views::iota(1, 20);
	for (int num : sequence) {
		std::cout << num << " ";
	}	


	std::cout << std::endl;
	std::vector<int> data_num = {5, 2, 8, 1, 7};
	std::ranges::sort(data_num, std::greater{});

	for (int num : data_num) {
		std::cout << num << " ";
	}
	std::cout << std::endl;


	std::unordered_map<int, std::string> umap;
	umap[1] = "one";
	umap[2] = "two";
	umap[5] = "five";
	umap[8] = "eight";

	auto key_views = std::views::keys(umap);
	std::vector<int> keys {key_views.begin(), key_views.end()};
	
	for (int& key : keys) {
		std::cout << key << " ";
	}
	std::cout << std::endl;


	auto value_views = std::views::values(umap);
	std::vector<std::string> values {value_views.begin(), value_views.end()};
	for (std::string& value : values) {
		std::cout << value << " ";
	}
	std::cout << std::endl;



	return 0;
}
