#pragma once

#include "Entities/Pipes/Pipe.hpp"

class PipePair {
public:
    PipePair(TextureManager& tm, Render& render, EventDispatcher& ed, CollisionManager& cm);

    void update(float deltaTime);
    bool isOffScreen() const;
    float getX() const;

private:
    Pipe topPipe;
    Pipe bottomPipe;
    float gapSize = 250.f;  // Space between pipes
};