#include <physics.hpp>
#include <entity.hpp>
#include <controls.hpp>

void eon::physics::Component::update() {

}

std::tuple<short, short> eon::physics::Component::getUserInput() {
    std::shared_ptr<eon::Component> compPtr = 
        entity.lock()->getComponent(ComponentType::Player).lock();
    
    // TODO: check if this even works
    std::shared_ptr<eon::controls::PlayerComponent> returnptr = static_pointer_cast<eon::controls::PlayerComponent>(compPtr); 

    return returnptr->getAxisMovement();
}

std::shared_ptr<eon::Component> eon::physics::Manager::createComponent(ComponentType a_type) {
    std::shared_ptr<eon::physics::Component> newComp(new eon::physics::Component());

    componentList.push_back(std::move(newComp));

    return newComp;
}

void eon::physics::Manager::deleteComponent(std::shared_ptr<eon::Component> a_comp) {
    componentList.remove(static_pointer_cast<eon::physics::Component>(a_comp));
}