#include <iostream>
#include <coroutine>

struct Generator {

    struct promise_type {
        int current_value;

        Generator get_return_object() {
            std::cout << "in get_return_object" << std::endl;
            return Generator{std::coroutine_handle<promise_type>::from_promise(*this)};
        }
    
        std::suspend_always initial_suspend() { 
            std::cout << "initial_suspend" << std::endl;
            return {}; 
        }
    
        std::suspend_always final_suspend() noexcept { 
            std::cout << "final_suspend()" << std::endl;    
            return {}; 
        }

        void return_void() {
            std::cout << "return void" << std::endl;
        }

        void unhandled_exception() { 
            std::cout << "unhandled_exception" << std::endl;
            //throw std::runtime_error("Oops!");
            std::cout << "unhandled_exception" << std::endl;    
            std::terminate(); 
        }

        std::suspend_always yield_value(int value) {
            std::cout << "yield_value(int value)" << std::endl;
            current_value = value;
            return {};
        }
    };

    using handle_type = std::coroutine_handle<promise_type>;
    handle_type coro;

    Generator(handle_type h) : coro(h) {
        //throw std::runtime_error("Something went wrong!");
        std::cout << "Generator(handle_type h" << std::endl;
    }
    ~Generator() { 
        std::cout << "~Generator()" << std::endl;
        if(coro) coro.destroy(); 
    }

    int next() {
        std::cout << "int next()" << std::endl;
        coro.resume();
        return coro.promise().current_value;
    }


};


Generator counter() {
    for (int i = 0; ; ++i) {
        std::cout << "before co_yield " << i << std::endl;
        co_yield i;
    }
}

int main() {

    Generator gen = counter();
    for (int i = 0; i < 5; ++i) {
        std::cout << gen.next() << std::endl;
    }
}
