#include <iostream>
#include <vector>
#include <list>
#include <utility>

template<typename K, typename V>
class HashMap {
private:
    static const int DEFAULT_CAPACITY = 16;
    static const double LOAD_FACTOR;
