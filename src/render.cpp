#include <memory>
#include <render.hpp>

void eon::render::TextureComponent::update() {

}

std::shared_ptr<eon::Component> eon::render::Manager::createComponent(ComponentType a_type) {
    std::shared_ptr<eon::render::Component> newComp = 
        std::make_shared<eon::render::TextureComponent>();

    componentList.push_back(newComp);

    return newComp;
}

void eon::render::Manager::deleteComponent(std::shared_ptr<eon::Component> a_comp) {
    componentList.remove(static_pointer_cast<eon::render::Component>(a_comp));
}