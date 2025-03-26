#include <iostream>
#include <new>


char * g_safety_buffer = NULL;

void my_new_handler() {
    if (g_safety_buffer) {
        delete [] g_safety_buffer;
        g_safety_buffer = NULL;
        std::cout << "[Free some pre_allocated memory]\n";
        return;
    }

    std::cout << "[No memory to free, throw bad_alloc]\n";
    throw std::bad_alloc();
}


int main() {

    enum { MEM_CHUNK_SIZE = 1024 * 1024 };
    std::set_new_handler(my_new_handler);
    g_safety_buffer = new char[1024 * MEM_CHUNK_SIZE];

    try {
        while(true) {        
            std::cout << "Trying another new ...\n";
            new char[200 * MEM_CHUNK_SIZE];
            std::cout << "...succeeded.\n";
        }
        
    } catch (const std::bad_alloc& e) {
        std::cout << "...failed.\n";
    }
    
    return 0;
}
