#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <memory>

class TextureManager{
    private:
        std::map<std::string, std::shared_ptr<sf::Texture>> textures;
        std::unordered_map<std::string, std::vector<std::pair<sf::IntRect, std::shared_ptr<sf::Texture>>>> spriteSheets;

    public:
        const sf::Texture& getTexture(const std::string& filename, bool repeated = false);
        const sf::Texture& getTexture(const std::string& filename, const sf::IntRect rect, bool repeated = false);

};