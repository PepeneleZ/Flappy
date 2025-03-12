#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <memory>

class TextureManager{
    private:
        std::map<std::string, std::shared_ptr<sf::Texture>> textures;

    public:
        const sf::Texture& getTexture(const std::string& filename);
};