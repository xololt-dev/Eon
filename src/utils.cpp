#include <utils.hpp>

void eon::Manager::update() {
    for (auto comp : componentList)
        comp->update();
}