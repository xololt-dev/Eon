#include "SDL_events.h"

#include "controls/controls_manager.hpp"
#include "controls/player_component.hpp"
#include "controls/ai_component.hpp"
#include "controls/game_key_actions.hpp"
#include "utils.hpp"

#include <iostream>

void eon::controls::Manager::update() {
    std::cout << "controls manager update start\n";

    SDL_Event event;

    SDL_PumpEvents();
    // If quit event
    if (SDL_PeepEvents(NULL,0,SDL_PEEKEVENT,SDL_QUIT,SDL_QUIT) > 0) {
        quit = true;
        return;
    }

    for (std::shared_ptr<Component> c : componentList) {
        std::cout << "controls component\n";
        if (c->getType() == ComponentType::Player)
            c->update();
    }

    std::cout << "controls manager update end\n";
}

std::shared_ptr<eon::Component> eon::controls::Manager::createComponent(ComponentType a_type) {
    std::shared_ptr<eon::controls::PlayerComponent> newComp = 
        std::make_shared<eon::controls::PlayerComponent>();

    componentList.push_back(newComp);

    return newComp;
}

void eon::controls::Manager::loadKeybinds() {
    keyMap[SDLK_UP] = to_underlying(GameKeyActions::Up);
    keyMap[SDLK_DOWN] = to_underlying(GameKeyActions::Down);
    keyMap[SDLK_LEFT] = to_underlying(GameKeyActions::Left);
    keyMap[SDLK_RIGHT] = to_underlying(GameKeyActions::Right);
}

void eon::controls::Manager::deleteComponent(std::shared_ptr<eon::Component> a_comp) {
    if (a_comp->getType() == ComponentType::Player)
        componentList.remove(std::static_pointer_cast<eon::controls::PlayerComponent>(a_comp));
    else if (a_comp->getType() == ComponentType::Computer)
        componentList.remove(std::static_pointer_cast<eon::controls::AIComponent>(a_comp));
}

std::tuple<short, short> eon::controls::Manager::getAxisMovement() {
    for (std::shared_ptr<eon::Component> comp : componentList) {
        if (comp->getType() == ComponentType::Player)
            return std::static_pointer_cast<eon::controls::PlayerComponent>(comp)->getAxisMovement();
    }
    
    return std::make_tuple(0, 0);
}