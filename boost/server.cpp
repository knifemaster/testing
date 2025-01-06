#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class Server {
    public:
        bool connect() {
            

        }

        bool send(std::string& message) {

        }

        bool receive(std::string& data) {
        }


    private:
        std::vector<int> connected_ports;
        size_t clients_count;
        std::vector<tcp::socket> sockets;

        int port = 1234;
        boost::asio::io_context io_context;
        tcp::acceptor aceptor(io_context, tcp::endpoint(tcp::v4(), port))
        tcp::socket socket(io_context);
}

int main(int argc, char* argv[])
{
    try {
        boost::asio::io_context io_context;
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 12345));
        tcp::socket socket(io_context);
        acceptor.accept(socket);
        std::string message = "Hello client\n";
        boost::system::error_code ignored_error;
    
    	boost::asio::write(socket, boost::asio::buffer(message), ignored_error);

    }
    catch(std::exception& e) {
        std::cerr << "Ошибка " << e.what() << std::endl;
    }
 
  return 0;
}
