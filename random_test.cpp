#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <random>

namespace random_utility {

enum class DistributionType {
    UNIFORM_INT_DISTRIBUTION,
    UNIFORM_REAL_DISTRIBUTION,
    BERNOULLI_DISTRIBUTION,
    BINOMIAL_DISTRIBUTION,
    GEOMETRIC_DISTRIBUTION,
    NEGATIVE_BINOMIAL_DISTRIBUTION,
    POISSON_DISTRIBUTION,
    EXPONENTIAL_DISTRIBUTION,
    GAMMA_DISTRIBUTION,
    WEIBULL_DISTRIBUTION,
    EXTREME_VALUE_DISTRIBUTION,
    NORMAL_DISTRIBUTION,
    LOGNORMAL_DISTRIBUTION,
    CHI_SQUARED_DISTRIBUTION,
    CAUCHY_DISTRIBUTION,
    FISHER_F_DISTRIBUTION,
    STUDENT_T_DISTRIBUTION,
    DISCRETE_DISTRIBUTION,
    PIECEWISE_CONSTANT_DISTRIBUTION,
    PIECEWISE_LINEAE_DISTRIBUTION,

};

enum class EngineType {
    LINEAR_CONGRUENTAL_ENGINE,
    MERSENNE_TWISTER_ENGINE,
    SUBTRACT_WITH_CARRY_ENGINE,
    DISCARD_BLOCK_ENGINE,
    INDEPENDENT_BITS_ENGINE,
    SHUFFLE_ORDER_ENGINE,


};

template<typename EngineType, typename Distribution, typename T>
class RandomGenerator {

    private:
        EngineType generator;
        Distribution dist;
        //ListRanges list_ranges;
    public:
        RandomGenerator() {

        }

        T generate_random_number() {
            return dist(generator);
        }

};

template<typename T>
double normal_distribution(T a, T b) {
	std::default_random_engine generator;
  	std::normal_distribution<double> distribution(10.5, 50.0);
	return distribution(generator);
}

}

int main() {

	random_utility::RandomGenerator<std::default_random_engine, std::uniform_real_distribution<float>, float> generator;
	random_utility::RandomGenerator<std::default_random_engine, std::uniform_int_distribution<int>, int> generator_int;
	random_utility::RandomGenerator<std::default_random_engine, std::normal_distribution<float>, float> normal_float;
	std::cout << random_utility::normal_distribution<float>(1, 100) << std::endl;
	std::cout << generator.generate_random_number() << std::endl;
    	std::cout << generator.generate_random_number() << std::endl;
    	std::cout << generator_int.generate_random_number() << std::endl;

	for (int i = 0; i < 10; i++) {
		std::cout << random_utility::normal_distribution<double>(10.0, 60.0) << std::endl;
	}

	return 0;
}
