#include "render/render_manager.hpp"
#include "render/render_component.hpp"
#include "render/texture_component.hpp"

void eon::render::Manager::update() {
    SDL_RenderClear(renderer);

    for (std::shared_ptr<eon::Component> comp : componentList)
        comp->update();

    SDL_RenderPresent(renderer);
} 

std::shared_ptr<eon::Component> eon::render::Manager::createComponent(ComponentType a_type) {
    std::shared_ptr<eon::render::Component> newComp (new eon::render::TextureComponent(this));
        //std::make_shared<eon::render::TextureComponent>();

    componentList.push_back(newComp);

    return newComp;
}

void eon::render::Manager::deleteComponent(std::shared_ptr<eon::Component> a_comp) {
    componentList.remove(std::static_pointer_cast<eon::render::Component>(a_comp));
}