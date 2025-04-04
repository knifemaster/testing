#include <cstring>
#include <stdexcept>
#include <ostream>

class StringView {

    public:

        StringView() : data_(nullptr), size_(0) {}
        StringView(const char* str) : data_(str), size_(str ? std::strlen(str) : 0) {}
        StringView(const char* str, size_t size) : data_(str), size_(size) {}
        StringView(const std::string& str) : data_(str.data()), size_(str.size()) {}
        
        const char* data() const { return data_; }
        size_t size() const { return size_; }
        bool empty() const { return size_ == 0; }

        char operator[](size_t pos) const { return data_[pos]; }

        char at(size_t pos) const {
            if (pos >= size_) {
                throw std::out_of_range("StringView::at");
            }
            return data_[pos];        
        }

}
