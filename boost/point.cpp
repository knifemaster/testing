#include <iostream>
#include <cmath>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/vector_sparse.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>



class Point {
    public:
        Point(double x, double y) : x(x), y(y) {}    
        
        constexpr double get_x()  {
            return x;
        }

        constexpr double get_y()  {
            return y;
        }

    private:
        double x;
        double y;

};

double distance(Point& a, Point& b) {
    double dx = a.get_x() - b.get_x();
    double dy = a.get_y() - b.get_y();
    return std::sqrt(dx * dx + dy* dy);
}

class DateAssistant {
    public:
        DateAssistant (std::string& date_) : date(boost::gregorian::from_simple_string(date_)) { }

    boost::gregorian::date get_date() {
        return date;
    }

    std::string get_date_string() {
        std::string str_date = boost::gregorian::to_simple_string(date);
        return str_date;
    }
    std::string get_current_date() {
        boost::gregorian::date current_date = boost::gregorian::day_clock::local_day();
        std::string str_date = boost::gregorian::to_simple_string(current_date);
        return str_date;

    }

    void add_months(size_t months) {
        date += boost::gregorian::months(months);
    }
    void add_days(size_t days) {
        date += boost::gregorian::days(days);
    }

    boost::gregorian::date difference_dates(std::string& other_date) {
        
        boost::gregorian::date date_diff = boost::gregorian::from_simple_string(other_date)
        
        boost::gregorian::date date_diff -= date;
        //date_diff = date - other_date;
        return date_diff;
    }
   
    private:
        boost::gregorian::date date;

};


int main() {

    using namespace boost::gregorian;

    std::string s = "2001-10-9";
    DateAssistant da = DateAssistant(s);
    //da.add_months(-3);
    //da.add_days(-4);
    for (size_t i = 0; i < 26; i ++) {
        da.add_days(1);
        std::cout << da.get_date_string() << std::endl;

    }
    std::cout << "for " << std::endl;
    //std::cout << da.get_current_date();



    std::string ss("2001-10-9"); //2001-October-09
    
    date d(from_simple_string(ss));
    
    //boost::gregorian::date (2010,1,1) + boost::gregorian::days(n)
    d += boost::gregorian::days(3);
    
    //std::string b = to_simple_string(d);

    //std::cout << "##"<<b << "BB"<<std::endl;

    std::cout << to_simple_string(d) << std::endl;  
    std::cout << d.year() << std::endl;  
    std::cout << d.month() << std::endl;  
    

/*
    date x_nowdays = day_clock::local_day();

    std::cout << x_nowdays <<std::endl;

    std::string s("2001-10-9"); //2001-October-09
    date d(from_simple_string(s));
    std::cout << to_simple_string(d) << std::endl;   

    date::ymd_type ymd = d.year_month_day();
    greg_weekday wd = d.day_of_week();
    std::cout << wd.as_long_string() << " "
                << ymd.month.as_long_string() << " "
                << ymd.day << ", " << ymd.year
                << std::endl;

*/

/*
    using namespace boost::numeric::ublas;

    scalar_vector<double> v1 (3);
    
    std::cout << v1 << v1[0] <<std::endl;

    mapped_vector<double> v (3, 3);
    for (unsigned i = 0; i < v.size (); ++ i)
        v (i) = i;
    std::cout << v << std::endl;

    identity_matrix<double> m (3);
    std::cout << m << std::endl;
    std::cout << m(0,0) << std::endl;
    std::cout << m(1,2) << std::endl;

    Point p1 = Point(200.0, 200.0);
    Point p2 = Point(600.0, 200.0);

    std::cout << distance(p1, p2); 
*/


}
