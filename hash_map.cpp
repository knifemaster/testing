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

public:
    HashMap() : buckets(DEFAULT_CAPACITY), size(0) {}
    
    void put(const K& key, const V& value) {
        int index = hash(key);
        
        
        for (auto& pair : buckets[index]) {
            if (pair.first == key) {
                pair.second = value; 
                return;
            }
        }

        buckets[index].emplace_back(key, value);
        size++;

        if ((double)size / buckets.size() > LOAD_FACTOR) {
            rehash();
        }
    }

    bool get(const K& key, V& value) const {
        int index = hash(key);

        for (const auto& pair : buckets[index]) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }

        return false;
    }

    bool remove(const K& key) {
        int index = hash(key);
        
        auto& bucket = buckets[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                size--;
                return true;
            }
        }
        
        return false;
    }

    bool contains(const K& key) const {
        int index = hash(key);

        for (const auto& pair : buckets[index]) {
            if (pair.first == key) {
                return true;
            }
        }

        return false;
    }

    
    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }
};

template<typename K, typename V>
const double HashMap<K, V>::LOAD_FACTOR = 0.75;


int main() {
    HashMap<std::string, int> map;

    map.put("one", 1);
    map.put("two", 2);
    map.put("three", 3);

    int value;
    if (map.get("two", value)) {
        std::cout << "two: " << value << std::endl;
    }

    std::cout << "Size: " << map.getSize() << std::endl;

    map.remove("two");
    std::cout << "Contains 'two': " << map.contains("two") << std::endl;
    std::cout << "Size after removal: " << map.getSize() << std::endl;

    return 0;
}
