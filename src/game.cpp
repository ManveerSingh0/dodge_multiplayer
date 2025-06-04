#include "game.hpp"


Game::Game(unsigned int height, unsigned int width, const std::string& title){
    window.create(sf::VideoMode({height, width}), title);
    player_manager.add_player(Player());
}

void Game::start(){

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

    window.clear(sf::Color::Cyan);
    player_manager.render(window);
    window.display();
  }
}