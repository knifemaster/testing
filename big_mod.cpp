#include <iostream>
#include <cstdint>
#include <xmmintrin.h>
#include <immintrin.h>
#include <iomanip>

int mod(std::string num, int a) {
	int res = 0;

	for (int i = 0; i < num.length(); i++) {
		res = (res * 10 + num[i] - '0') % a;
	}

	return res;

}


struct BigInt {
	uint8_t high = 0;
	uint8_t low = 0;
	
	void overflow() {
		if (low >= 255) {
			high++;
			low = 0;
		}
			
	}

	void print_number() {
		uint16_t number = high;
       		number <<= 8;
	
		number = number | low; 	
	
		std::cout << unsigned(number) << std::endl;
	}


	void print_hex_number() {
		std::stringstream ss;
		uint8_t num = 12;
		ss << std::hex << num;
		std::string s = ss.str();
		std::cout << "hex number is " << s << std::endl;
	
	}

};



int main() {

	BigInt integer;
	integer.high = 10;
	integer.low = 255;
	std::cout << unsigned(integer.high) << " " << unsigned(integer.low) << std::endl;
	integer.overflow();

	integer.print_number();

	integer.print_hex_number();

	std::cout << unsigned(integer.high) << " " << unsigned(integer.low) << std::endl;


	std::string num = "12316767678678";
	std::cout << mod(num, 10) << std::endl;

	std::string num2 = "1234";
	std::cout << mod(num2, 5) << std::endl;

	uint64_t n = 12316767678678;
	std::cout << n % 10 << std::endl;
	std::cout << 1234 % 5 << std::endl;


	alignas(16) float a[4] = {1.0f, 2.0f, 3.0f, 4.0f};
	alignas(16) float b[4] = {5.0f, 6.0f, 7.0f, 8.0f};

	alignas(16) float result[4];

	__m128 vecA = _mm_load_ps(a);
	__m128 vecB = _mm_load_ps(b);

	__m128 vecResult = _mm_add_ps(vecA, vecB);
	_mm_store_ps(result, vecResult);

	std::cout << "Result: ";
	for (int i = 0; i < 4; i++) {
		std::cout << result[i] << " ";
	}
	std::cout << std::endl;

	return 0;

}
