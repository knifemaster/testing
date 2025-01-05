#include <iostream>
#include <string>
#include <map>


int main() {

	std::map<std::string, int> data = {{"apple", 3}, {"banana", 5}, {"cherry", 7}};

	if (const auto it = data.find("banana"); it != data.end()) {
		std::cout << "founded element " << it->first << " " << it->second << std::endl;
	} else {
		std::cout << "not found " << std::endl;
	}


	return 0;
}
