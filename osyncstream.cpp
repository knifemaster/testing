#include <syncstream>
#include <iostream>
#include <thread>
#include <vector>

void worker(int id) {
    std::osyncstream out(std::cout);
    for (int i = 0; i < 3; ++i) {
        out << "Поток " << id << ", итерация " << i << '\n';
    }
    // Буфер автоматически сбрасывается при разрушении out
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(worker, i);
    }
    
    for (auto& t : threads) {
        t.join();
    }
    
    return 0;
}


/*

#include <chrono>
#include <iostream>
#include <syncstream>
#include <thread>

using namespace std::chrono_literals;
 
void foo()
{
    std::thread::id this_id = std::this_thread::get_id();
 
    std::osyncstream(std::cout) << "thread " << this_id << " sleeping...\n";
 
    std::this_thread::sleep_for(500ms);
}
 
int main()
{
    std::jthread t1{foo};
    std::jthread t2{foo};
}

*/
