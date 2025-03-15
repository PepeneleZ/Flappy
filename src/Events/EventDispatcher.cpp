#include "Events/EventDispatcher.hpp"

void EventDispatcher::addListener(EventType type, std::function<void(Event*)> listener){
    listeners[type].push_back(listener);
}

void EventDispatcher::dispatch(Event* event) {
    for (const auto& listener : listeners[event->getType()]) {
        listener(event);
    }
}