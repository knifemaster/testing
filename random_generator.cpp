

#include <iostream>

#include <optional>
#include <string>
#include <cmath>

#include <future>
#include <coroutine>

#include <memory>
#include <type_traits>
#include <random>
#include <chrono>
#include <Print>
#include <set>
#include <list>


struct promise {};

struct coroutine : std::coroutine_handle<promise>
{
    using promise_type = ::promise;
};


std::optional<std::string> get_name(const int choice) {
    if (choice == 1) {
        return std::optional<std::string>("Black");
    }
    else {
        return std::nullopt;
    }
}

template<typename T>
class Divisor {
    private:
        T a;

    public:
        Divisor(int value): a(value) {}

        T divide(const T& value) const {
            return value / 2;
        }
};


namespace db {

    enum class Types {
        Integer,
        Boolean,
        Character,
        String,
        None
    };
    
    enum class Erorrs {
        WrongSqlString,
        WrongCursorPos,
        WrongType,
        WrongConnectionString,
        WrongPassword,
        WrongUser,
        WrongDataType,
        WrongStatement,
        WrongObject,
    };

    
    /*
    class Statement {
        private:
            RowType type;
            Data& data;
            std::unordered_map<std::string, std::string> result_set;

        public:
            void execute_sql() {
                
            }

            //
            void get_fields() {
            }

            void get_values() {
            
            }

    };
    */
    /*
    class IDatabase {


        virtual ~IDatabase() {}

        virtual Statement& commit() = 0 {

        }

        virtual CursorType& get_cursor() = 0 {
        }

        virtual CursorPos& get_position() = 0 {
        }


    };
 */

    /*
    class Database : public IDatabase {
        private:
            std::string sql_query;
            CursorType& curr;
            CursorPos& pos;

            std::string connection_string;
            std::string user;
            std::string password;

          
        public:
            Database() {
                                
            }


            
            virtual ~Database() {}

            Statement& commit(const std::string& sql_query) {

            }

            CursorType& get_cursor() const {
                return curr;
            
            }

            CursorPos& get_position() const {
                return pos;
            }

            std::optional<CursorPos> set_cursor_position(uint64_t cur_pos) {
            
            }

    }
    */

/*
    template<typename T, std::enable_if<std::is_enum<T>>::value, Types>
    Types get_row_type(const T& type) {
      
    }
    */

};

class Data {
private:
    std::vector<std::string> data;
    std::unordered_map<int, std::string> cache;
    std::unordered_map<std::string, std::string> params;

public:
    Data(std::vector<std::string>& values) : data(values) {

    }
    std::string& operator[](const std::string& param) {
        return data.at(std::atoi(param.c_str()));
    }

    static friend std::ostream& operator<<(std::ostream& os, const Data& data) {
        os << data;
        return os;
    }
    
};

template<>
struct std::hash<Data> 
{
    Data p_data;
};


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

template<typename T, typename LowerBound, typename UpperBound>
class Pair {
    public:
        LowerBound lower;
        UpperBound upper;

};

template<typename T, Pair>
class ListRanges {
    private:
        std::vector<T> list_ranges = std::vector() 

    public:
        ListRanges(T& value, std::vector<Pair>& params) : {
        
        }

        std::list<T>& get_list_ranges() const {
            return list_ranges;
        }

};



template<typename T, typename = std::enable_if<std::is_arithmetic<T>::value>::type>
class Seed {
    private:
        T seed;
    public:
        Seed() : seed() {
            std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
            seed = static_cast<T>(start.time_since_epoch().count());
        }

        T get_seed() {
            return seed;
        }

         
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



/*
template<typename T, typename E>
class RandomColorGenerator: RandomGenerator {
       

};
*/

/*
template<typename T, typename E>
class RandomPointGenerator: public RandomGenerator {
    private:
        std::default_random_engine engine;
        //std::uniform_real_distribution<float> dist_float(lower, upper);
        std::uniform_real_distribution<float> dist_float;

        RandomPointGenerator() { }

        std::vector<Point> randomize_points(std::vector<Point>& vector_points, float lower, float upper) {
            std::vector<Point> vec_point;


        }

};
*/

/*
class RandomGeneratePointsStorage {
    std::vector<Point> points {};

    RandomGeneratePointsStorage(const size_t lower, const size_t upper) {
        points.reserve(upper);

        for (size_t i = lower; i < upper; ++i) {
            points.push_back(Point());
        }
    }

    void randomize_points(const float lower,const float upper) {
        for (Point& p : points) {
            p.set_random_point(lower, upper);
        }
    }


};
*/


class Point {
    
    private:
        float x;
        float y;
        float z;
    
    public:

        Point() : x(0.0f), y(0.0f), z(0.0f) {}

        Point(float x, float y, float z) : x(x), y(y), z(z) {
        }
        
        void set_random_point(const float lower,const float upper) {
            std::default_random_engine engine;
            std::uniform_real_distribution<float> dist_float(lower, upper);
            x = dist_float(engine);
            y = dist_float(engine);
            z = dist_float(engine);

        }

        void set_random_x_point(const float lower, const float upper) {
            std::default_random_engine engine;
            std::uniform_real_distribution<float> dist_float(lower, upper);
            x = dist_float(engine);
        }
        void set_random_y_point(const float lower, const float upper) {
            std::default_random_engine engine;
            std::uniform_real_distribution<float> dist_float(lower, upper);
            y = dist_float(engine);

        }
        void set_random_z_point(const float lower, const float upper) {
            std::default_random_engine engine;
            std::uniform_real_distribution<float> dist_float(lower, upper);
            z = dist_float(engine);

        }



        std::tuple<float, float, float> get_point() const {
            std::tuple<float, float, float> param = std::make_tuple(z, y, z);
            return param;
        }

        float get_x() const {
            return x;
        }

        float get_y() const {
            return y;
        }

        float get_z() const {
            return z;
        }

        static friend std::ostream& operator<<(std::ostream& os, const Point& point) {
            os << "x:" << point.x << "\n" << "y:" << point.y << "\n" << "z:" << point.z << "\n";
            return os;
        }
};



int main()
{
    RandomGenerator<std::default_random_engine, std::uniform_real_distribution<float>, float> generator;
    RandomGenerator<std::default_random_engine, std::uniform_int_distribution<int>, int> generator_int;

    std::cout << generator.generate_random_number() << std::endl;
    std::cout << generator_int.generate_random_number() << std::endl;

    ListRanges<int, int, int> ranges;


    //using generator = std::default_random_engine;
    
    //generator gen;

    //using dist = std::uniform_real_distribution<float>;

    //dist dist_float;

    //std::cout << dist_float(gen) << std::endl;

    Seed<int> seed_int = Seed<int>();
    Seed<float> seed_float = Seed<float>();
    
    std::cout << std::abs(seed_int.get_seed()) << std::endl;
    std::cout << seed_float.get_seed() << std::endl;

    for (size_t i = 0; i < 10; ++i) {
        Seed<int> seed_intval = Seed<int>();

        std::cout << seed_intval.get_seed() % 100000 << std::endl;
    }

    /*
    std::cout << sizeof(Point) << std::endl;

    const float lower_bound = 50.0f;
    const float upper_bound = 100.0f;

    std::default_random_engine engine;
    std::uniform_int_distribution<int> dist(1, 20);
    std::uniform_real_distribution<float> dist_real(70.0, 150.0);

    
    Point p(2.0f, 4.4f, 6.3f);
    p.set_random_point(100.0f, 200.0f);


    std::print("Hello world");
    std::cout << p.get_x() << " " << p.get_y() << " " << p.get_z();
    std::cout << p << std::endl;

    auto [x, y, z] = p.get_point();
    std::cout << x << " " << y << " " << z;


    std::vector<Point> vec_point = { Point(), Point(), Point(), Point() };


    for (Point& p : vec_point) {
        p.set_random_y_point(lower_bound, upper_bound);
    }

    for (const Point& p : vec_point) {
        std::cout << p << "\n";
    }

 


    std::vector<std::string> numbers{ "1", "2", "3", "4", "5" };
    Data* data = new Data(numbers);

    std::cout << data->operator[]("2") << std::endl;
    std::cout <<"hash" << std::hash<float>()(3.2f) << std::endl;
    std::cout << "hash" << std::hash<float>()(3.3f) << std::endl;
    std::cout << "hash" << std::hash<float>()(3.3f) << std::endl;
    std::cout << "hash" << std::hash<float>()(3.3f) << std::endl;
    std::cout << "hash string = " << std::hash<std::string>()("hello world1") << std::endl;
    std::cout << "hash string = " << std::hash<std::string>()("nello world") << std::endl;
    std::cout << "hash string = " << std::hash<std::string>()("hello world") << std::endl;



    auto name = get_name(1);
    if (name.has_value()) {
        std::cout << name.value() << std::endl;
    }

    std::cout << "Hello World!\n";
    */
}
