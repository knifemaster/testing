#include <iostream>
#include <cstdint>
#include <iomanip>
#include <string>
#include <bitset>

struct BigInt {
	uint64_t high;
	uint64_t low;

	BigInt operator+(const BigInt& other) const {
	
		BigInt result;
		result.low = low + other.low;
		result.high = high + other.high + (result.low < low ? 1:0);

		return result;
	
	}

	BigInt operator*(const BigInt& other) const {
		uint64_t a = high;
		uint64_t b = low;
		uint64_t c = other.high;
		uint64_t d = other.low;

		uint64_t ac = a * c;
		uint64_t bd = b * d;
		uint64_t ab_cd = (a + b) * (c + d);
		uint64_t cross = ab_cd - ac - bd;
		BigInt result;
		result.low = bd + ((cross & 0xFFFFFFFFFFFFF) << 64);

		result.high = ac + (cross >> 64);

		return result;
			
	}

};

void print_big_int(const BigInt& number) {
	__uint128_t full_number = (__uint128_t(number.high) << 64) | number.low;
	std::string res;

	while (full_number > 0) {
		res = char('0'+(full_number%10)) + res;
		full_number /= 10;
	}

	if (res.empty()) {
		std::cout << "0" << std::endl;
	} else {
		std::cout << res << std::endl;
	}

}

void print_binary_int(const BigInt& number) {
	std::string binary_high = std::bitset<64>(number.high).to_string();
	std::string binary_low = std::bitset<64>(number.low).to_string();

	std::string res = binary_high + " - " + binary_low;

	std::cout << res << std::endl;


}




int main() {

	//BigInt num = {0x0000000000000001, 0x0000000000000001};
	//BigInt num2 = {0x0000000000000000, 0x00000000000000002};
	BigInt num = {1, 1};
	BigInt num2 = {0, 2};
	//BigInt num2 = {1, 1};
	print_big_int(num);
	print_binary_int(num);
	print_binary_int(num2);
	BigInt res = num * num2;
	print_binary_int(res);

	return 0;
}


