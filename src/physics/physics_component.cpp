#include "physics/physics_component.hpp"
#include "physics/displacement_command.hpp"
#include "controls/player_component.hpp"
#include "entity/entity.hpp"
#include "manager.hpp"

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