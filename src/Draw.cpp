#include "Draw.hpp"

Draw::Draw() : window(sf::VideoMode({1064u, 800u}), "CMake SFML Project") {
    window.setFramerateLimit(144);
}

void Draw::add(const sf::Drawable& drawable, int layer){
    drawables[layer].push_back(&drawable);
}

void Draw::render(){

    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
    }



    window.clear();

    for(const auto& layer : drawables){
        for(const auto* drawable : layer.second){
            window.draw(*drawable);
        }
    }

    window.display();
        
}



bool Draw::isOpen(){
    return window.isOpen();
}


