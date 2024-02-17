#include <render.hpp>

void eon::render::Component::update() {

}

std::shared_ptr<eon::Component> eon::render::Manager::createComponent(ComponentType a_type) {
    std::shared_ptr<eon::render::Component> newComp(new eon::render::Component()); // = new eon::controls::PlayerComponent();

    componentList.push_back(std::move(newComp));

    return newComp;
}

void eon::render::Manager::deleteComponent(std::shared_ptr<eon::Component> a_comp) {
    componentList.remove(static_pointer_cast<eon::render::Component>(a_comp));
}