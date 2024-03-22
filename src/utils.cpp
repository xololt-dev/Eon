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

void eon::Manager::sendCommand(const std::shared_ptr<eon::Command>& a_command) {
    std::cout << "sendCommand " << a_command.use_count() << "\n" << a_command << "\n";
    // << systemsManager << "\n";
    systemsManager->sendCommand(a_command);
}