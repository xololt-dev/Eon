#include "entity/entity.hpp"

#include <memory>

std::shared_ptr<eon::Component> eon::entity::Entity::getComponent(eon::ComponentType a_type) {
    std::shared_ptr<eon::Component> returnPtr;

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
