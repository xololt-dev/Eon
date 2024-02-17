#include "utils.hpp"
#include <entity.hpp>
#include <memory>

bool eon::entity::Entity::addComponent(std::shared_ptr<Component> a_component) {
    componentsList.push_back(a_component);
    
    return true;
}

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

    for (auto a : componentsList) {
        if (a->getType() == a_type) {
            returnPtr = a;
            break;
        }
    }
    
    return returnPtr;
}

void eon::entity::Manager::addEntity() {
    // Create components (get vec of components from the SystemManager)
    // Create entity with those componenets
}

void eon::entity::Manager::deleteEntity() {
    // Delete components
    // Delete entity
}