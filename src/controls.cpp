#include "SDL_events.h"
#include "SDL_keycode.h"
#include "utils.hpp"
#include <SDL2/SDL.h>
#include <controls.hpp>

#include <memory>
#include <iostream>

// TODO: Proper controls handling (currently one button at the time for some reason)

void eon::controls::PlayerComponent::update() {
    SDL_Event event;
    // Screen coordinates change
    short xAxisChange = 0, 
          yAxisChange = 0;

    // Check for keyboard input
    while ( SDL_PollEvent( &event ) ){
        switch( event.type ){
            // Look for a keypress
            case SDL_KEYDOWN:
                // Check the SDLKey values and move change the coords
                switch( event.key.keysym.sym ){
                    case SDLK_LEFT:
                        xAxisChange -= 1;
                        std::cout << "Left\n";
                        break;
                    case SDLK_RIGHT:
                        xAxisChange += 1;
                        std::cout << "Right\n";
                        break;
                    case SDLK_UP:
                        yAxisChange -= 1;
                        std::cout << "Up\n";
                        break;
                    case SDLK_DOWN:
                        yAxisChange += 1;
                        std::cout << "Down\n";
                        break;
                    default:
                        break;
                }
                break;
            // We must also use the SDL_KEYUP events to zero the x 
            // and y velocity variables. But we must also be       
            // careful not to zero the velocities when we shouldn't
            case SDL_KEYUP:
                switch( event.key.keysym.sym ){
                    case SDLK_LEFT:
                        std::cout << "Left r\n";
                        xAxisChange += 1;
                        break;
                    case SDLK_RIGHT:
                        std::cout << "Right r\n";
                        xAxisChange -= 1;
                        break;
                    case SDLK_UP:
                        std::cout << "Up r\n";
                        yAxisChange += 1;
                        break;
                    case SDLK_DOWN:
                        std::cout << "Down r\n";
                        yAxisChange -= 1;
                        break;
                    default:
                        break;
                }
                break;
            
            default:
                // If event is not something we service here, push back onto SDL event queue
                // SDL_PushEvent(&event);
                break;
        }
    }
    
    // xAxisChange;
    // yAxisChange;
    xAxis = xAxisChange;
    yAxis = yAxisChange;
}

void eon::controls::Manager::update() {
    SDL_Event event;

    SDL_PumpEvents();
    // If quit event
    if (SDL_PeepEvents(NULL,0,SDL_PEEKEVENT,SDL_QUIT,SDL_QUIT) > 0) {
        quit = true;
        return;
    }

    for (auto c : componentList)
        if (c->getType() == ComponentType::Player)
            c->update();
}

std::shared_ptr<eon::Component> eon::controls::Manager::createComponent(ComponentType a_type) {
    std::shared_ptr<eon::controls::PlayerComponent> newComp(new eon::controls::PlayerComponent()); // = new eon::controls::PlayerComponent();

    componentList.push_back(std::move(newComp));

    return newComp;
}

void eon::controls::Manager::loadKeybinds() {
    keyMap[SDLK_UP] = to_underlying(GameKeyActions::Up);
    keyMap[SDLK_DOWN] = to_underlying(GameKeyActions::Down);
    keyMap[SDLK_LEFT] = to_underlying(GameKeyActions::Left);
    keyMap[SDLK_RIGHT] = to_underlying(GameKeyActions::Right);
}