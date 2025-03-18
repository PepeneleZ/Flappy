#include "Entities/Pipes/Pipe.hpp"

Pipe::Pipe(TextureManager&  tm, Render& render, EventDispatcher& ed, CollisionManager& cm) 
    : texture(tm.getTexture("../../textures/sheet.png", sf::IntRect({690,51}, {104, 640})))
    , sprite(texture)
{
    sprite.setOrigin(sf::Vector2(52.f, 640.f));

    collisionBox = sf::FloatRect(sf::Vector2(sprite.getPosition().x - texture.getSize().x / 2, sprite.getPosition().y + texture.getSize().y / 2), sf::Vector2(104.f, 640.f));

    cm.addCollidable(this);

    render.add(sprite, 2);

    if(showCollisionBox){
        collisionShape.setSize(collisionBox.size);
        collisionShape.setPosition(collisionBox.position);
        collisionShape.setFillColor(sf::Color::Transparent); 
        collisionShape.setOutlineThickness(1);
        collisionShape.setOutlineColor(sf::Color::Red);
        render.add(collisionShape, 10);
    }
}

void Pipe::update(float deltaTime){
    updateCollisionBox();
    move(deltaTime);
}

void Pipe::updateCollisionBox(){
    collisionBox.position.x = sprite.getPosition().x - texture.getSize().x / 2;
    if(showCollisionBox) collisionShape.setPosition(collisionBox.position);
}

void Pipe::move(float deltaTime){
    velocity = -speed * deltaTime;
    sprite.move(sf::Vector2(velocity, 0.f));
}

sf::FloatRect Pipe::getBounds() const {
    return collisionBox;
}

void Pipe::onCollision(Event* event) {

}

ObjectType Pipe::getType() const {
    return ObjectType::Pipes;
}

CollisionCategory Pipe::getCollisionCategory() const{
    return CollisionCategory::Enviroment;
}

bool Pipe::isDestroyed() const {
    return false;
}

void Pipe::clean(Render& render, CollisionManager& cm){
    render.remove(sprite, 2);
    if(showCollisionBox) render.remove(collisionShape, 10);
    cm.removeCollidable(this);
}
