#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstdint>
#include <limits>

using namespace std;

uint32_t Ferm(uint32_t a,uint32_t p) {
	if (p == 0) {
		return 1;
	}
	uint32_t res = static_cast<uint32_t>(pow(a, p - 1)) % p;
	return res;
}


uint64_t factorial(int n) {
	if (n == 0 | n == 1) {
		return 1;
	}

	int64_t f = 1;
	for (size_t i = 1; i <= n; ++i) {
		f *= i;
	}

	return f;
}

int64_t combinations(int n, int k) {
	int64_t n_fact = factorial(n);
	int64_t k_fact = factorial(k);
	int64_t n_minus_k_fact = factorial(n-k);
	return n_fact / (k_fact * n_minus_k_fact);
		
}

int countSetBits(string& s) {
	int count = 0;
	for (size_t i = 0; i < s.size(); i++) {
		if(s[i] == '1') count++;
	}
	return count;
}

int countSetBitsShift(int number) {
	int count = 0;
	while(number > 0) {
		if ((number & 1) == 1) {
			count++;
		}
		number >>= 1;	
	}

	return count;

}

string toBinaryString(int number) {
	if (number == 0) 
		return "0";
	
	string binary = "";
	
	while(number > 0) {
		binary = to_string(number % 2) + binary;
		number /= 2;
	}
	return binary;
}


int countReducibleNumbers(string& s, int k) {


	vector<int> dp;
	dp.reserve(k+1);

	unsigned int modulus = pow(10, 9) + 7;

	cout << modulus << endl;

	//dp.push_back(k + 1);
       	//dp.push_back(0);	

	uint32_t result = 1;

	int count = countSetBits(s);



	cout << count << std::endl;

	cout << "combs" << combinations(s.size(), count) << endl;


	cout << "fermas " << Ferm(count, combinations(s.size(), count )) << endl;

	if (count == 1) {
		return 1;
	}

	cout << "fermas " << Ferm(count, combinations(count, k)) << endl;

	while(count != 1) {
		string str_number = toBinaryString(count);
		cout << str_number << endl; 
		count = countSetBits(str_number);
		
		result++;

		//cout << "combinations"  << 32 << "  " << combinations(count, k) << endl;
		cout << "fermas " << Ferm(count, combinations(count, k)) << endl;
		
	}

	return result;


}




int main() {
	
	cout << "max value " << uint64_t(-1) << endl;
	cout << numeric_limits<uint64_t>::max()<<endl;		
	
	vector<uint64_t> factorials;
	factorials.reserve(32);
	for (size_t i = 0; i < 32; ++i) {
		factorials.push_back(factorial(i));
	
	}

	for (const auto& factor : factorials) {
		cout << factor << endl;
	}

	string binary_number = "111";
	
	
	int k = 1;
	cout << "aresult = " << "hello world " << countReducibleNumbers(binary_number, 1) << std::endl; 
	//cout << "ferms" << Ferm(2, 7) << endl;
	//cout << combinations(7, 5) << endl;
	cout << pow(10, 9) << endl;
}
