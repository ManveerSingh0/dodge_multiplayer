#include "entity_manager.hpp"

void Entity_Manager::add_player(const Player& player){
    this->players.push_back(player);
}

void Entity_Manager::render(sf::RenderWindow& window){
    for(Player p : players){
        p.render(window);
    }
}