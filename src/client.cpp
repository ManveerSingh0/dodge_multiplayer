#include <SFML/Network.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <iostream>

int main() {
    sf::TcpSocket socket;
    if (socket.connect({127,0,0,1}, 5000) != sf::TcpSocket::Status::Done) {
        std::cout << "Error: Could not connect to server" << std::endl;
        return 1;
    }
    std::cout << "Connected to server" << std::endl;

    while (true) {
        std::string message;
        std::cout << "Enter message: ";
        std::getline(std::cin, message);
        sf::Packet packet;
        packet << message;
        if (socket.send(packet) != sf::TcpSocket::Status::Done) {
            std::cout << "Error: Could not send message" << std::endl;
        }
        sf::Packet reply;
        if (socket.receive(reply) == sf::TcpSocket::Status::Done) {
            std::string received;
            if (reply >> received) {
                std::cout << "Received from server: " << received << std::endl;
            }
        }
    }
    return 0;
}
