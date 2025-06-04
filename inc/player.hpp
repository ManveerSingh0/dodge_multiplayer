#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>


class Player{
    public:
        Player();
        void render(sf::RenderWindow& window);

    private:
        sf::RectangleShape player_body;

        void move();
};


#endif //PLAYER_HPP