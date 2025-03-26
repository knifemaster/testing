#include <iostream>
#include <new>

void handler() {
    std::cout << "allocation failed" << "\n";
    std::set_new_handler(nullptr);
}


int main() {

        size_t allocations_count = 0u;
        std::set_new_handler(handler);

        try {
        
            while(true) {
                constexpr size_t GB = 1024u * 1024u * 1024;
            
                char* buffer = new char[GB];
                for (size_t i = 0u; i < GB; i += 4096u) {
                    buffer[i] = 100;
                }

                std::cout << "allocated " << ++allocations_count << " GB" << "\n";
            }
        
        } catch (const std::bad_alloc& e) {
            std::cout << e.what() << "\n";
        }

        std::cout << "finally allocated " << allocations_count << " GB" << "\n";

        return 0;

}
