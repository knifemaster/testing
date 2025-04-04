#include <cstring>
#include <stdexcept>
#include <ostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <string_view> 



class StringView {
public:
    // Типы
    using value_type = char;
    using pointer = char*;
    using const_pointer = const char*;
    using reference = char&;
    using const_reference = const char&;
    using const_iterator = const char*;
    using iterator = const_iterator;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;
    using reverse_iterator = const_reverse_iterator;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
