#include <SFML/Network.hpp>
#include <SFML/Network/Packet.hpp>
#include <SFML/Network/TcpListener.hpp>
#include <cstdlib>
#include <iostream>


int main() {
  sf::TcpListener listener;
  if (listener.listen(5000) != sf::TcpListener::Status::Done) {
    std::cout << "Error: Coult not list on port 5000\n";
    return EXIT_FAILURE;
  }


  std::cout << "Server is listening on port 5000\n";

  sf::TcpSocket client;
  if (listener.accept(client) != sf::TcpListener::Status::Done) {
    std::cout << "Error: Could not accept client\n";
    return EXIT_FAILURE;
  }

  std::optional<sf::IpAddress> remote_address = client.getRemoteAddress();
  std::cout << "Client connected: " << remote_address->toString();

  while (true) {
    sf::Packet packet;
    std::string message;


    if (client.receive(packet) == sf::TcpSocket::Status::Done) {
      if (packet >> message) {
        std::cout << "Received from client: " << message << '\n';
        sf::Packet reply;
        reply << message;
	if(client.send(reply) == sf::TcpSocket::Status::Done){};
      }
    }
  }
}
