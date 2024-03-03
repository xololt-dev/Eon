#include "physics/physics_manager.hpp"
#include "physics/physics_component.hpp"

#include <memory>

std::shared_ptr<eon::Component> eon::physics::Manager::createComponent(ComponentType a_type) {
    std::shared_ptr<eon::physics::Component> newComp(new eon::physics::Component());

    componentList.push_back(std::move(newComp));

    return newComp;
}

void eon::physics::Manager::deleteComponent(std::shared_ptr<eon::Component> a_comp) {
    componentList.remove(std::static_pointer_cast<eon::physics::Component>(a_comp));
}