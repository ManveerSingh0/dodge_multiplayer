#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include <vector>

class Entity_Manager{
    public:
        void render(sf::RenderWindow& window);
        void add_player(const Player& player);
    private:
    std::vector<Player> players;
};




#endif //ENTITY_MANAGER_HPP