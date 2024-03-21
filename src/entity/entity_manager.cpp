#include "entity/entity_manager.hpp"
#include "component.hpp"
#include "controls/ai_component.hpp"
#include "controls/player_component.hpp"
#include "entity/entity.hpp"
#include "enums.hpp"
#include "physics/physics_component.hpp"

#include <memory>

// TODO: Think about return values - should they be (shared) ptrs or IDs?
std::shared_ptr<eon::entity::Entity> eon::entity::Manager::addEntity(
    unsigned long long a_id, EntityType a_type, glm::vec3 a_position) {
    // Create entity and return a pointer to it
    
    std::shared_ptr<eon::entity::Entity> newEntity = std::make_shared<eon::entity::Entity>(a_id, a_type, a_position); 
    entitiesList.push_back(newEntity);
    
    return newEntity;
}

void eon::entity::Manager::deleteEntity() {
    // Delete components
    // Delete entity
}

void eon::entity::Manager::addComponent(std::shared_ptr<eon::Component> a_component, unsigned long long a_id) {
    ComponentType type = a_component->getType();
    std::shared_ptr<Entity> entity;

    for (std::shared_ptr<Entity>& entityInside : entitiesList) {
        if (entityInside->getId() == a_id) {
            entity = entityInside;
            break;
        }
    }

    // entity->addComponent(std::static_pointer_cast<eon::Component>(a_component), type);

    switch (type) {
        case ComponentType::Player:
            entity->addComponent(
                std::static_pointer_cast<eon::controls::PlayerComponent>(a_component), 
                type);
            break;
        case ComponentType::Computer:
            entity->addComponent(
                std::static_pointer_cast<eon::controls::AIComponent>(a_component), 
                type);
            break;
        case ComponentType::Physics:
            entity->addComponent(
                std::static_pointer_cast<eon::physics::Component>(a_component), 
                type);
            break;
        case ComponentType::Render:
            entity->addComponent(
                std::static_pointer_cast<eon::render::Component>(a_component), 
                type);
            break;
        case ComponentType::Audio:
            entity->addComponent(
                std::static_pointer_cast<eon::audio::Component>(a_component), 
                type);
            break;
    }
}