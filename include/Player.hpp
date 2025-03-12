# pragma once

#include <SFML/Graphics.hpp>
#include "Draw.hpp"

class Player{
    private:
        sf::Sprite sprite;

    public:
        Player(const sf::Texture& texture, Draw& draw);
        void update();
};