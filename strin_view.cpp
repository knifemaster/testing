#include <cstring>
#include <stdexcept>
#include <ostream>

class StringView {

    public:

        StringView() : data_(nullptr), size_(0) {}
        StringView(const char* str) : data_(str), size_(str ? std::strlen(str) : 0) {}
        StringView(const char* str, size_t size) : data_(str), size_(size) {}
        StringView(const std::string& str) : data_(str.data()), size_(str.size()) {}


}
