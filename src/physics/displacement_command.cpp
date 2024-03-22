#include "physics/displacement_command.hpp"
#include "entity/entity.hpp"
#include <memory>

void eon::physics::DisplacementCommand::execute() {
    if (!srcEntity.use_count())
        return;

    std::shared_ptr<entity::Entity> sharedEntity(srcEntity);
    
    sharedEntity->setPosition(displacement + sharedEntity->getPosition());
}