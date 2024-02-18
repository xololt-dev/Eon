#include "controls.hpp"
#include <core.hpp>
#include <memory>

void eon::SystemsManager::update() {
    controls.update();
}

std::shared_ptr<eon::Component> eon::SystemsManager::createComponent(ComponentType a_type) {
    std::shared_ptr<Component> returnPtr;
    
    switch (a_type) {
        case ComponentType::Player:
        case ComponentType::Computer:
            return controls.createComponent(a_type);
            break;
        case ComponentType::Physics:
            return physics.createComponent(a_type);
            break;
        case ComponentType::Render:
            return render.createComponent(a_type);
            break;
        case ComponentType::Audio:
            return audio.createComponent(a_type);
            break;
    }
}

void eon::SystemsManager::deleteComponent(std::shared_ptr<controls::PlayerComponent> a_player) {
    controls.deleteComponent(a_player);
}

void eon::SystemsManager::deleteComponent(std::shared_ptr<controls::AIComponent> a_computer) {
    controls.deleteComponent(a_computer);
}

void eon::SystemsManager::deleteComponent(std::shared_ptr<physics::Component> a_physics) {
    physics.deleteComponent(a_physics);
}

void eon::SystemsManager::deleteComponent(std::shared_ptr<audio::Component> a_audio) {
    audio.deleteComponent(a_audio);
}

void eon::SystemsManager::deleteComponent(std::shared_ptr<render::Component> a_render) {
    render.deleteComponent(a_render);
}