#define SDL_MAIN_HANDLED

#include <iostream>
#include <unistd.h>
#include <memory>
#include <ostream>
/*
#include <external/imgui/imgui.h>
#include <external/imgui/imgui_impl_sdl2.h>
#include <external/imgui/imgui_impl_opengl3.h>
*/
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_render.h>

#include <core.hpp>
#include <entity/entity.hpp>
#include <physics/physics.hpp>
#include <controls/controls.hpp>
#include <utils.hpp>
#include <systems_manager.hpp>

int main(int argc, char* argv[]) {
    // Setup SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0) {
        printf("Error: %s\n", SDL_GetError());
        return -1;
    }

    // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    // GL ES 2.0 + GLSL 100
    const char* glsl_version = "#version 100";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#elif defined(__APPLE__)
    // GL 3.2 Core + GLSL 150
    const char* glsl_version = "#version 150";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG); // Always required on Mac
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#endif

    // From 2.0.18: Enable native IME.
#ifdef SDL_HINT_IME_SHOW_UI
    SDL_SetHint(SDL_HINT_IME_SHOW_UI, "1");
#endif

    // Create window with graphics context
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    SDL_GL_SetSwapInterval(1); // Enable vsync

    // Input test
    std::shared_ptr<eon::SystemsManager> sm = std::make_shared<eon::SystemsManager>();
    std::unique_ptr<eon::entity::Manager> entMan = std::make_unique<eon::entity::Manager>();
    entMan->setSystemsManager(sm.get());

    std::shared_ptr<eon::entity::Entity> entity = entMan->addEntity(0, eon::entity::EntityType::Player);
    std::shared_ptr<eon::controls::PlayerComponent> player = 
        std::static_pointer_cast<eon::controls::PlayerComponent>
        (sm->createComponent(eon::ComponentType::Player));
    
    std::cout << player.use_count() << std::endl;
    
    entity->addComponent(player, player->getType());
    std::cout << player.use_count() << std::endl;
    player->setEntity(entity);
    entity.reset();

    std::cout << player.use_count() << std::endl;

    SDL_Event event;
    while (!sm->getQuit()) {
        sm->update();
    }

    sm.reset();
    entMan.reset();
    player.reset();
    
    std::cout << (player.get() == nullptr) << std::endl;
    
    SDL_Quit();

    return 0;
}