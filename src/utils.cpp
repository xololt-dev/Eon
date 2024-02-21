#include <SDL2/SDL_image.h>
#include "SDL_surface.h"
#include <cstddef>
#include <memory>
#include <utils.hpp>

void eon::Manager::update() {
    for (std::shared_ptr<Component> comp : componentList)
        comp->update();
}

void eon::PNGTexture::load(std::string a_path) {
    std::unique_ptr<SDL_Surface> loadedSurface(IMG_Load(a_path.c_str()));  
    
    if (loadedSurface == NULL){
        // Error handle
    }
    else {
        surface = std::unique_ptr<SDL_Surface>(SDL_ConvertSurface(loadedSurface.get(), loadedSurface->format, 0));
            // std::make_unique<SDL_Surface>(*SDL_ConvertSurface(loadedSurface.get(), loadedSurface->format, 0));
        if (surface == NULL) {
            // Error handle
        }

        SDL_FreeSurface(loadedSurface.get());
    }
}