#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

// для переделки

std::string
display(std::chrono::nanoseconds ns){
    std::ostringstream os;
    typedef std::chrono::duration<int, std::ratio<86400>> days;
    auto h = std::chrono::duration_cast<std::chrono::hours>(ns);
    ns -= h;
    auto m = std::chrono::duration_cast<std::chrono::minutes>(ns);
    ns -= m;
    auto s = std::chrono::duration_cast<std::chrono::seconds>(ns);
    os << std::setw(2) << h.count() << ":"
       << std::setw(2) << m.count() << ":"
       << std::setw(2) << s.count();
    return os.str();
};

int main(){
    auto cooldown = std::chrono::hours(24);    
    
    // You need to save the last spawn time when it happens.
    // This here simulate 1 hour has passed
    auto last_spawn_time = std::chrono::system_clock::now() - std::chrono::hours(3);

    // Compute the next spawn time
    auto next_spawn = last_spawn_time + cooldown;

    // Finally, find the std::duration to show how much time left:
    auto next_spawn_in = next_spawn - std::chrono::system_clock::now();
    std::cout << "Next spawn in: ";
    auto duration = display(std::chrono::duration_cast<std::chrono::nanoseconds>(next_spawn_in));
    std::cout << duration << std::endl;

    return 0;
}
