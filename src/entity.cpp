#include <entity.hpp>

bool eon::entity::Entity::addComponent(Component& a_component) {
    this->componentsList.push_back(&a_component);
    
    return false;
}