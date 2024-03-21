#include "manager.hpp"
#include "systems_manager.hpp"

#include <memory>

void eon::Manager::update() {
    // Execute commands
    for (std::shared_ptr<eon::Command>& c : commandsPending)
        c->execute();    
    
    commandsPending.clear();

    // Update components
    for (std::shared_ptr<Component>& comp : componentList)
        comp->update();
}

void eon::Manager::sendCommand(std::shared_ptr<eon::Command>& a_command) {
    std::cout << "sendCommand\n";
    systemsManager->sendCommand(a_command);
}