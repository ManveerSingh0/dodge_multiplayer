#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>


class Game{
    private:
    sf::RenderWindow window;
    public:
        Game(unsigned int height, unsigned int width, std::string& title);
        void start();
};



#endif //GAME_HPP