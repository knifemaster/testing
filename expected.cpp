#include <cmath>
#include <expected>
#include <iomanip>
#include <iostream>
#include <string_view>


enum class parseJ_error {
    invalid_input,
    overflow
};

auto parse_number(std::string_view& str) -> std::expected<double, parse_error> {
    const char* begin = str.data();
    char* end;
    double retval = std::strtod(begin, &end);

    if (begin == end)
        return std::unexpected(parse_error::invalid_input);
    else if (std::isinf(retval))
        return std::unexpected(parse_error::overflow);

    str.remove_prefix(end - begin);
    return retval;
}
