#include "TextureManager.hpp"
#include <string>
#include <map>
#include <memory>

const sf::Texture& TextureManager::getTexture(const std::string& filename){
    
    auto it = textures.find(filename);
    if(it != textures.end()){
        return *(it->second);
    }

    auto texture = std::make_shared<sf::Texture>();
    if(!texture->loadFromFile(filename)){
        throw std::runtime_error("Failed to load texture: " + filename);
    }

    textures[filename] = texture;

    return *texture;
}