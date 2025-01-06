#include <boost/multiprecision/cpp_int.hpp>
#include <boost/random.hpp>

int main() {

	using namespace boost::multiprecision;
	using namespace boost::random;

	typedef independent_bits_engine<mt19937, 256, cpp_int> generator_type;

	generator_type gen;

	std::cout << std::hex << std::showbase;

	for (unsigned i = 0; i < 10; ++i) {
		std::cout << gen() << std::endl;
	}

	typedef independent_bits_engine<mt19937, 512, uint512_t> generator512_type;

	generator512_type gen512;

	//std::cout << std::hex<< std::showbase;

	for (unsigned i = 0; i < 10; ++i) {
		std::cout << gen512() << std::endl;
	}

	return 0;

}

