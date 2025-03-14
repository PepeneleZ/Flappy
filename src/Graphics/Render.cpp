#include "Graphics/Render.hpp"

void Render::add(const sf::Drawable& drawable, int layer){
    drawables[layer].push_back(&drawable);
}

void Render::draw(sf::RenderWindow& window){
    for(const auto& layer : drawables){
        for(const auto* drawable : layer.second){
            window.draw(*drawable);
        }
    }

}




