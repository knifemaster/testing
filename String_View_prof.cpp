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


    constexpr const_reference operator[](size_type pos) const { return data_[pos]; }
    const_reference at(size_type pos) const {
        if (pos >= size_) {
            throw std::out_of_range("StringView::at");
        }
        return data_[pos];
    }
    constexpr const_reference front() const { return *data_; }
    constexpr const_reference back() const { return *(data_ + size_ - 1); }
    constexpr const_pointer data() const noexcept { return data_; }

    // Емкость
    constexpr size_type size() const noexcept { return size_; }
    constexpr size_type length() const noexcept { return size_; }
    constexpr bool empty() const noexcept { return size_ == 0; }

    // Модификаторы
    constexpr void remove_prefix(size_type n) {
        data_ += n;
        size_ -= n;
    }
    constexpr void remove_suffix(size_type n) {
        size_ -= n;
    }
    constexpr void swap(StringView& other) noexcept {
        std::swap(data_, other.data_);
        std::swap(size_, other.size_);
    }

        constexpr StringView substr(size_type pos, size_type count = npos) const {
        if (pos > size_) {
            throw std::out_of_range("StringView::substr");
        }
        const size_type rlen = std::min(count, size_ - pos);
        return StringView(data_ + pos, rlen);
    }

    // Поиск
    constexpr size_type find(StringView v, size_type pos = 0) const noexcept {
        if (pos > size_ || v.size() > size_ - pos) {
            return npos;
        }
        if (v.empty()) {
            return pos;
        }
        const_iterator it = std::search(begin() + pos, end(), v.begin(), v.end());
        return it == end() ? npos : static_cast<size_type>(it - begin());
    }

    constexpr size_type find(char c, size_type pos = 0) const noexcept {
        return find(StringView(&c, 1), pos);
    }

    // Сравнение
    constexpr int compare(StringView rhs) const noexcept {
        const int cmp = std::memcmp(data_, rhs.data_, std::min(size_, rhs.size_));
        return cmp != 0 ? cmp : (size_ == rhs.size_ ? 0 : size_ < rhs.size_ ? -1 : 1);
    }

    // Операторы сравнения
    friend constexpr bool operator==(StringView lhs, StringView rhs) noexcept {
        return lhs.size() == rhs.size() && lhs.compare(rhs) == 0;
    }
    friend constexpr bool operator!=(StringView lhs, StringView rhs) noexcept {
        return !(lhs == rhs);
    }
    friend constexpr bool operator<(StringView lhs, StringView rhs) noexcept {
        return lhs.compare(rhs) < 0;
    }
    friend constexpr bool operator<=(StringView lhs, StringView rhs) noexcept {
        return lhs.compare(rhs) <= 0;
    }
    friend constexpr bool operator>(StringView lhs, StringView rhs) noexcept {
        return lhs.compare(rhs) > 0;
    }
    friend constexpr bool operator>=(StringView lhs, StringView rhs) noexcept {
        return lhs.compare(rhs) >= 0;
    }

    // Преобразование в std::string
    explicit operator std::string() const {
        return std::string(data_, size_);
    }

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, StringView v) {
        return os.write(v.data_, v.size_);
    }

private:
    const char* data_;
    size_type size_;
};

namespace std {
    template<> struct hash<StringView> {
        size_t operator()(const StringView& sv) const noexcept {
            // Реализация hash как в std::string_view
            return std::hash<std::string_view>()(std::string_view(sv.data(), sv.size()));
        }
    };
}


#include <iostream>
#include <vector>

int main() {
    const char* cstr = "Hello, world!";
    std::string str = "Modern C++";

    StringView sv1(cstr);
    StringView sv2(str);
    StringView sv3(cstr, 5); // "Hello"

    std::cout << "sv1: " << sv1 << "\n";
    std::cout << "sv2: " << sv2 << "\n";
    std::cout << "sv3: " << sv3 << "\n";

    // Использование итераторов
    std::vector<char> chars(sv1.begin(), sv1.end());

    // Поиск
    size_t pos = sv1.find("world");
    if (pos != StringView::npos) {
        StringView sub = sv1.substr(pos);
        std::cout << "Found: " << sub << "\n";
    }

    // Удаление префикса
    sv3.remove_prefix(1);
    std::cout << "After remove_prefix: " << sv3 << "\n"; // "ello"

    return 0;
}
