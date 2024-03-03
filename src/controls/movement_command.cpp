#include "controls/movement_command.hpp"
#include "physics/physics_component.hpp"
#include "entity/entity.hpp"

void eon::controls::MovementCommand::execute() {
    if (!srcEntity.use_count())
        return;
    
    std::shared_ptr<eon::physics::Component> physics = std::static_pointer_cast<eon::physics::Component>
        (srcEntity.lock()->getComponent(ComponentType::Physics));
    
    physics->includeMovement({xAxis, yAxis, 0.0f});
}