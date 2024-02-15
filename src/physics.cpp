#include <physics.hpp>

void eon::physics::Component::update() {

}

std::shared_ptr<eon::Component> eon::physics::Manager::createComponent(ComponentType a_type) {
    std::shared_ptr<eon::physics::Component> newComp(new eon::physics::Component()); // = new eon::controls::PlayerComponent();

    componentList.push_back(std::move(newComp));

    return newComp;
}