# pragma once

#include <SFML/Graphics.hpp>
#include <map>

class Render {
    public:
        void add(const sf::Drawable& drawable, int layer);
        void remove(const sf::Drawable& drawable, int layer);
        void draw(sf::RenderWindow& window);

    private:
        std::map<int, std::vector<const sf::Drawable*>> drawables;
};