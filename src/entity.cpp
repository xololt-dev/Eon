#include <entity.hpp>

bool eon::entity::Entity::addComponent(Component& a_component) {
    this->componentsList.push_back(&a_component);
    
    return true;
}

void eon::entity::Manager::addEntity() {
    // Create components (get vec of components from the SystemManager)
    // Create entity with those componenets
}