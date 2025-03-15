#pragma once

#include <vector>
#include <functional>
#include <unordered_map>
#include "Events/Event.hpp"

class EventDispatcher {
    public:
        void addListener(EventType type, std::function<void(Event*)> listener);
        void dispatch(Event* event);

    private:
        std::unordered_map<EventType, std::vector<std::function<void(Event*)>>> listeners;
};    