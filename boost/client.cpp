#include <boost/asio.hpp>
#include <iostream>
#include <array>
using boost::asio::ip::tcp;

int main() {
    
        boost::asio::io_context io_context;
        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints = resolver.resolve("127.0.0.1", "12345");

        tcp::socket socket(io_context);

        boost::asio::connect(socket, endpoints);
        std::array<char, 128> buffer;
        boost::system::error_code error;
        size_t len = socket.read_some(boost::asio::buffer(buffer), error);

        
        std::cout.write(buffer.data(), len);
      
        return 0;

}
