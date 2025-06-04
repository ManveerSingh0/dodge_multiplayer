#include "SFML/Window/Keyboard.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

int main(int argc, char* argv[]) {
  sf::RenderWindow window(sf::VideoMode({800, 600}), "Dodge Multiplayer");

  
  while (window.isOpen()) {
    while (std::optional<sf::Event> event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
	window.close();
      }
      if (const sf::Event::KeyPressed *key_pressed =
              event->getIf<sf::Event::KeyPressed>()) {
        if (key_pressed->scancode == sf::Keyboard::Scancode::Escape) {
	  window.close();
        }
      }
    }

    window.clear();
    window.display();
  }
  return 0;
}
