#include "glm/fwd.hpp"
#include "utils.hpp"
#include <entity.hpp>

#include <memory>

std::weak_ptr<eon::Component> eon::entity::Entity::getComponent(eon::ComponentType a_type) {
    std::weak_ptr<eon::Component> returnPtr;

    switch (a_type) {
        case ComponentType::Player:
            if (type != EntityType::Player) 
                return returnPtr;
            break;
        case ComponentType::Computer:
            if (type != EntityType::Computer) 
                return returnPtr;
            break;
        case ComponentType::Physics:
            if (type == EntityType::Static || type == EntityType::StaticAudio)
                return returnPtr;
            break;
        case ComponentType::Render:
            break;
        case ComponentType::Audio:
            if (type == EntityType::Dynamic || type == EntityType::Static)
                return returnPtr;
            break;
        default:
            break;
    }

    for (std::shared_ptr<Component> a : componentsList) {
        if (a->getType() == a_type) {
            returnPtr = a;
            break;
        }
    }
    
    return returnPtr;
}

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