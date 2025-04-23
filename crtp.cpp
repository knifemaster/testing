#include <iostream>

template <typename T>
class Counter {
    public:
        static int count;

        Counter() { ++count; }
        ~Counter() { --count; }

        static void PrintCount() {
            std::cout << "Total objects: " << count << std::endl;
        }
};
