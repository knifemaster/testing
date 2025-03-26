#include <iostream>
#include <vector>
#include <list>
#include <utility>

template<typename K, typename V>
class HashMap {
private:
    static const int DEFAULT_CAPACITY = 16;
    static const double LOAD_FACTOR;

    std::vector<std::list<std::pair<K, V>>> buckets;
    int size;

    int hash(const K& key) const {
        std::hash<K> hasher;
        return hasher(key) % buckets.size();
    }

    void rehash() {
        std::vector<std::list<std::pair<K, V>>> oldBuckets = buckets;
        buckets.clear();
        buckets.resize(oldBuckets.size() * 2);
        size = 0;

        for (auto& bucket : oldBuckets) {
            for (auto& pair : bucket) {
                put(pair.first, pair.second);
            }
        }
    }
