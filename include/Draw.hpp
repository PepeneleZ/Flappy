# pragma once

#include <SFML/Graphics.hpp>
#include <map>

class Draw {
    private:
        std::map<int, std::vector<const sf::Drawable*>> drawables;

    public:
        sf::RenderWindow window;
        Draw();
        bool isOpen();
        void add(const sf::Drawable& drawable, int layer);
        void render();
};