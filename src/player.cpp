#include "player.hpp"


Player::Player(){
    player_body.setSize({30.0f,30.0f});
    player_body.setFillColor(sf::Color::Red);
    player_body.setPosition({100,100});
}

void Player::render(sf::RenderWindow& window){
    window.draw(player_body);
}