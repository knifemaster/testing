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


class GameCharacter {
private:
    std::string name;
    int health;

public:
    GameCharacter(const std::string& name, int health) : name(name), health(health) {}

    void display() const {
        std::cout << "Персонаж: " << name << " (HP: " << health << ")" << std::endl;
    }

    void attack() const {
        std::cout << name << " атакует!" << std::endl;
    }
};


class CharacterList : public CharacterCollection {
private:
    std::vector<GameCharacter> characters;

public:
    void addCharacter(const GameCharacter& character) {
        characters.push_back(character);
    }

    size_t size() const {
        return characters.size();
    }

    GameCharacter* getCharacter(size_t index) {
        if (index >= characters.size()) {
            return nullptr;
        }
        return &characters[index];
    }

    std::unique_ptr<Iterator> createIterator() override;
};

class CharacterIterator : public Iterator {
private:
    CharacterList* collection;
    size_t currentIndex;

public:
    CharacterIterator(CharacterList* col) : collection(col), currentIndex(0) {}

    bool hasNext() const override {
        return currentIndex < collection->size();
    }

    GameCharacter* next() override {
        if (!hasNext()) {
            return nullptr;
        }
        GameCharacter* character = collection->getCharacter(currentIndex);
        currentIndex++;
        return character;
    }
};

std::unique_ptr<Iterator> CharacterList::createIterator() {
    return std::make_unique<CharacterIterator>(this);
}
