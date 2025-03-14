#include "Graphics/TextureManager.hpp"
#include <string>
#include <map>
#include <unordered_map>
#include <memory>
#include <iostream>

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

const sf::Texture& TextureManager::getTexture(const std::string& filename, sf::IntRect rect){
    
    std::cout << "beu";
    auto sheetIt = spriteSheets.find(filename);
    if(sheetIt != spriteSheets.end()){
        for(const auto& pair : sheetIt->second){
            if(pair.first == rect){
                return *pair.second;
            }
        }
    }

    auto texture = std::make_shared<sf::Texture>();
    if(!texture->loadFromFile(filename, false ,rect)){
        throw std::runtime_error("Failed to load texture: " + filename);
    }

    spriteSheets[filename].emplace_back(rect, texture);

    return *texture;


}