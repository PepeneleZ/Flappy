#include <SFML/Graphics.hpp>

#include "Draw.hpp"
#include "TextureManager.hpp"
#include "Player.hpp"
#include "Background.hpp"

#include <iostream>



int main()
{

    Draw draw;
    TextureManager textureManager;

    Background bg(textureManager.getTexture("../../images/background.png"), draw);
    Player player(textureManager.getTexture("../../images/textures/Bird.png"), draw);

    while(draw.isOpen()){
        player.update();
        draw.render();
    }
    

}
