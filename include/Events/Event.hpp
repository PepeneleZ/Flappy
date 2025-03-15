#pragma once

enum class EventType {
    Collision
};

class Event{
    public:
        virtual ~Event() = default;
        virtual EventType getType() const = 0;
};