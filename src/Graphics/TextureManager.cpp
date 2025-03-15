#include "Graphics/TextureManager.hpp"
#include <string>
#include <map>
#include <unordered_map>
#include <memory>
#include <iostream>

const sf::Texture& TextureManager::getTexture(const std::string& filename, bool repeated){
    
    auto it = textures.find(filename);
    if(it != textures.end()){
        auto& texture = *(it->second);
        if(repeated) texture.setRepeated(repeated); 

        return texture;
    }

    auto texture = std::make_shared<sf::Texture>();
    if(!texture->loadFromFile(filename)){
        throw std::runtime_error("Failed to load texture: " + filename);
    }

    textures[filename] = texture;
    
    auto& textureRef = *texture;
    if(repeated) textureRef.setRepeated(repeated);

    return textureRef;
}

const sf::Texture& TextureManager::getTexture(const std::string& filename, sf::IntRect rect, bool repeated){
    
    auto sheetIt = spriteSheets.find(filename);
    if(sheetIt != spriteSheets.end()){
        for(const auto& pair : sheetIt->second){
            if(pair.first == rect){
                auto& texture = *pair.second;
                if(repeated) texture.setRepeated(repeated);

                return texture;
            }
        }
    }

    auto texture = std::make_shared<sf::Texture>();
    if(!texture->loadFromFile(filename, false ,rect)){
        throw std::runtime_error("Failed to load texture: " + filename);
    }

    spriteSheets[filename].emplace_back(rect, texture);

    auto& textureRef = *texture;
    if(repeated) textureRef.setRepeated(repeated);

    return textureRef;


}
