#include "Graphics/Render.hpp"
#include <bits/stdc++.h>

void Render::add(const sf::Drawable& drawable, int layer){
    drawables[layer].push_back(&drawable);
}

void Render::remove(const sf::Drawable& drawable, int layer) {
    auto layerIt = drawables.find(layer);
    if (layerIt != drawables.end()) {

        auto& drawableVector = layerIt->second;

        auto it = std::find(drawableVector.begin(), drawableVector.end(), &drawable);
        if (it != drawableVector.end()) {
            drawableVector.erase(it);
        }
    }
}

void Render::draw(sf::RenderWindow& window){
    for(const auto& layer : drawables){
        for(const auto* drawable : layer.second){
            window.draw(*drawable);
        }
    }

}




