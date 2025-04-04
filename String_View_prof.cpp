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


    static constexpr size_type npos = static_cast<size_type>(-1);

    // Конструкторы
    constexpr StringView() noexcept : data_(nullptr), size_(0) {}
    constexpr StringView(const char* str) : data_(str), size_(str ? strlen(str) : 0) {}
    constexpr StringView(const char* str, size_type len) : data_(str), size_(len) {}
    StringView(const std::string& str) noexcept : data_(str.data()), size_(str.size()) {}

    // Запрещаем копирование с неконстантным источником
    StringView(char* str) = delete;
    StringView(char* str, size_type len) = delete;


    constexpr const_iterator begin() const noexcept { return data_; }
    constexpr const_iterator end() const noexcept { return data_ + size_; }
    constexpr const_iterator cbegin() const noexcept { return begin(); }
    constexpr const_iterator cend() const noexcept { return end(); }
    const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(end()); }
    const_reverse_iterator rend() const noexcept { return const_reverse_iterator(begin()); }
    const_reverse_iterator crbegin() const noexcept { return rbegin(); }
    const_reverse_iterator crend() const noexcept { return rend(); }
