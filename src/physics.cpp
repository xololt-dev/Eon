#include "utils.hpp"
#include <physics.hpp>
#include <entity.hpp>
#include <controls.hpp>

#include <memory>

void eon::physics::DisplacementCommand::execute() {
    srcEntity->setPosition(displacement);
}

void eon::physics::Component::update() {
    // Calc acceleration
    // Calc velocity
    velocity += acceleration * static_cast<float>(elapsed.count());
    // Calc displacement
    // Send command
    std::shared_ptr<eon::entity::Entity> passPtr(getEntity());
    std::shared_ptr<eon::physics::DisplacementCommand> command = 
        std::make_shared<eon::physics::DisplacementCommand>(velocity, passPtr);
    std::shared_ptr<eon::Command> sendCommand = std::static_pointer_cast<eon::Command>(command);
    manager.lock()->sendCommand(sendCommand);
}

std::tuple<short, short> eon::physics::Component::getUserInput() {
    std::shared_ptr<eon::Component> compPtr = 
        entity.lock()->getComponent(ComponentType::Player);
    
    // TODO: check if this even works
    std::shared_ptr<eon::controls::PlayerComponent> returnptr = 
        std::static_pointer_cast<eon::controls::PlayerComponent>(compPtr); 

    return returnptr->getAxisMovement();
}

std::shared_ptr<eon::Component> eon::physics::Manager::createComponent(ComponentType a_type) {
    std::shared_ptr<eon::physics::Component> newComp(new eon::physics::Component());

    componentList.push_back(std::move(newComp));

    return newComp;
}

void eon::physics::Manager::deleteComponent(std::shared_ptr<eon::Component> a_comp) {
    componentList.remove(std::static_pointer_cast<eon::physics::Component>(a_comp));
}