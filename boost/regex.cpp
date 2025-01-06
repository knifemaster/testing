#include <iostream>

#include <boost/regex.hpp>
#include <string>

//#define BROKEN_REGEX "(([A-Z][a-z]+ *?){1,4}) g"
#define BROKEN_REGEX "(([A-Z][a-z])) g"
std::string match_boost(std::string in) {
	boost::regex re{BROKEN_REGEX};
	boost::smatch match;
	if (boost::regex_search(in, match, re)) {
		return match[1];
	}
	return "NO_MATCH";
}

int main() {
	std::cout << "hello world" << std::endl;
	//std::string in = "Alpha gamma";
	//std::string in = "Alpha Beta gamma";
	std::string in = "Az g Bz g";
	std::cout << match_boost(in) << std::endl;

}
