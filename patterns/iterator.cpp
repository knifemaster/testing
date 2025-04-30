#include <iostream>
#include <vector>
#include <memory>


class GameCharacter;

class Iterator {
    public:
        virtual ~Iterator() = default;
        virtual bool hasNext() const = 0;
        virtual GameCharacter* next() = 0;
};


class CharacterCollection {
public:
    virtual ~CharacterCollection() = default;
    virtual std::unique_ptr<Iterator> createIterator() = 0;
};
