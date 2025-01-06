#include <string>
#include <iomanip>
#include <iostream>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

int main() {

	std::string input {"461327846781265784365784326578653875435432"};
	boost::multiprecision::uint256_t i {input};

	std::stringstream ss;

	ss << std::hex << i;
	std::string s = ss.str();
	std::cout << s << std::endl;

	std::vector<unsigned char> v {s.begin(), s.end()};



	std::vector<unsigned char> vv;
	boost::multiprecision::uint256_t ii { input };
	export_bits(ii, std::back_inserter(vv), 8);

	for (auto c : vv) {
		std::cout << std::hex << (int)c;
	}

	std::string inkput {"543574358943758943758947389574389574389574839754893758943758943758943758943758947389574389574389574389754389758943798543584935435943"};
	boost::multiprecision::uint1024_t i1024 {inkput};

	std::cout << i1024 << std::endl;

	return 0;
}
