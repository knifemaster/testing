#include <cstdio>
#include <utility>

struct Lifetime {
    Lifetime() noexcept { puts("Lifetime() [default constructor]"); }
    Lifetime(const Lifetime&) noexcept {
        puts("Lifetime(const Lifetime&) [copy constructor]");
    }
    Lifetime(Lifetime&&) noexcept {
        puts("Lifetime(Lifetime&&) [move constructor]");
    }
    ~Lifetime() noexcept { puts("~Lifetime() [destructor]"); }

    Lifetime &operator=(const Lifetime&) noexcept {
        puts("operator=(const Lifetime&) [copy assignment]");
        return *this;
    }

    Lifetime &operator=(Lifetime&&) noexcept {
        puts("operator=(Lifetime&&) [move assignment]");
        return *this;
    }

};

Lifetime f1() {
    return Lifetime{};
}

Lifetime f2() {
    return f1();
}

Lifetime f3() {
    return f2();
}


int main() {
//    Lifetime l = f3();

//    auto l = []() { Lifetime{}; return f3(); };
//    l();
    auto lt = Lifetime{};
    auto l = [lt = std::move(lt)] () {};
    auto l2 = l;
}
