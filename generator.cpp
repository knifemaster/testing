/*
#include <iostream>
#include <generator>

template<typename T>
struct Tree {
	T value;
	Tree* left{};
	Tree* right{};

	std::generator<const T&> traverse_inorder() const {
		if (left) 
			co_yield std::ranges::elements_of(left->traverse_inorder());
		co_yield value;

		if (right)
			co_yield std::ranges::elements_of(right->traverse_inorder());
	}
};


int main() {
	Tree<char> tree[] {
	
	
                                    {'D', tree + 1, tree + 2},
        //                            │
        //            ┌───────────────┴────────────────┐
        //            │                                │
                    {'B', tree + 3, tree + 4},       {'F', tree + 5, tree + 6},
        //            │                                │
        //  ┌─────────┴─────────────┐      ┌───────────┴─────────────┐
        //  │                       │      │                         │
          {'A'},                  {'C'}, {'E'},                    {'G'}
	
	};

	for (char x : tree->traverse_inorder())
		std::cout << x << ' ';

	std::cout << '\n';


}
*/


#include <coroutine>
#include <iostream>
#include <optional>

// Простой генератор на основе корутин
template<typename T>
class Generator {
public:
    struct promise_type {
        T value;
        std::suspend_always yield_value(T val) {
            value = val;
            return {};
        }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        Generator get_return_object() { return Generator{this}; }
        void return_void() {}
        void unhandled_exception() { std::terminate(); }
    };

    using handle_type = std::coroutine_handle<promise_type>;

    explicit Generator(promise_type* p)
        : coro(handle_type::from_promise(*p)) {}

    ~Generator() {
        if (coro) coro.destroy();
    }

    std::optional<T> next() {
        if (!coro.done()) {
            coro.resume();
            return coro.promise().value;
        }
        return std::nullopt;
    }

private:
    handle_type coro;
};

// Пример использования
Generator<int> generate_numbers(int start, int end) {
    for (int i = start; i <= end; ++i) {
        co_yield i;
    }
}

int main() {
    auto gen = generate_numbers(1, 5);
    while (auto num = gen.next()) {
        std::cout << *num << " ";
    }
    return 0;
}
