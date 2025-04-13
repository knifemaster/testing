#include <boost/type_index.hpp>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <limits>
#include <type_traits>
 
template<typename T>
void print_max_value_of()
{
    constexpr T max{std::numeric_limits<T>::max()};
 
    std::cout << std::setw(16) << boost::typeindex::type_id<T>() << ": ";
    if constexpr (std::is_floating_point_v<T>)
        std::cout << std::defaultfloat << max << " = " << std::hexfloat << max << '\n';
    else
    {
        constexpr auto m{static_cast<unsigned long long>(max)};
        std::cout << std::dec << m << " = " << std::hex << m << '\n';
    }
}
 
int main()
{
    std::cout << std::showbase;
 
    print_max_value_of<bool>();
    print_max_value_of<short>();
    print_max_value_of<int>();
    print_max_value_of<std::streamsize>();
    print_max_value_of<std::size_t>();
    print_max_value_of<char>();
    print_max_value_of<char16_t>();
    print_max_value_of<wchar_t>();
    print_max_value_of<float>();
    print_max_value_of<double>();
    print_max_value_of<long double>();
}

//            bool: 1 = 0x1
//           short: 32767 = 0x7fff
//             int: 2147483647 = 0x7fffffff
//            long: 9223372036854775807 = 0x7fffffffffffffff
//   unsigned long: 18446744073709551615 = 0xffffffffffffffff
//            char: 127 = 0x7f
//        char16_t: 65535 = 0xffff
//         wchar_t: 2147483647 = 0x7fffffff
//           float: 3.40282e+38 = 0x1.fffffep+127
//          double: 1.79769e+308 = 0x1.fffffffffffffp+1023
//     long double: 1.18973e+4932 = 0xf.fffffffffffffffp+16380

