#include "physics/displacement_command.hpp"
#include "entity/entity.hpp"

void eon::physics::DisplacementCommand::execute() {
    if (!srcEntity.use_count())
        return;

    srcEntity.lock()->setPosition(displacement);
}