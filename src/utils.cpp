#include <memory>
#include <utils.hpp>

void eon::Manager::update() {
    for (std::shared_ptr<Component> comp : componentList)
        comp->update();
}