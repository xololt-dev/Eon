#include <core.hpp>

void eon::SystemsManager::update() {

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
