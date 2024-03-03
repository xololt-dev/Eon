#include "entity/entity_manager.hpp"

#include <memory>

std::shared_ptr<eon::entity::Entity> eon::entity::Manager::addEntity(
    unsigned int a_id, EntityType a_type, glm::vec3 a_position) {
    // Create entity and return a pointer to it
    
    std::shared_ptr<eon::entity::Entity> newEntity = std::make_shared<eon::entity::Entity>(a_id, a_type, a_position); 
    entitiesList.push_back(newEntity);
    
    return newEntity;
}

void eon::entity::Manager::deleteEntity() {
    // Delete components
    // Delete entity
}