#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_events.h>

#include "controls/player_component.hpp"
#include "command.hpp"
#include "controls/movement_command.hpp"
#include "manager.hpp"

#include <iostream>
#include <memory>

// TODO: Proper controls handling (currently one button at the time for some reason)
void eon::controls::PlayerComponent::update() {
    std::cout << "PlayerComponent update\n";

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
    
    std::shared_ptr<MovementCommand> command = std::make_shared<MovementCommand>(xAxis, yAxis, entity);
    std::shared_ptr<Command> sendCommand = std::static_pointer_cast<eon::Command>(command);
    std::cout << "Command to be sent\n" << command.get() << "\n";
    manager->sendCommand(sendCommand);
    std::cout << "Command sent\n";
}