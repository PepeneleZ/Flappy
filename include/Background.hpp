# pragma once

#include <SFML/Graphics.hpp>
#include "Draw.hpp"

class Background {
    private:
        sf::Sprite sprite;
    
    public:
        Background(const sf::Texture& texture, Draw& draw);
};