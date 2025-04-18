#include <iostream>
#include <memory>
#include <string>


class Product {
    public:
        virtual ~Product() = default;
        virtual void Use = 0;

};
