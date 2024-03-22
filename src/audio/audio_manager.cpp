#include "audio/audio_manager.hpp"
#include "audio/audio_component.hpp"

std::shared_ptr<eon::Component> eon::audio::Manager::createComponent(ComponentType a_type) {
    std::shared_ptr<eon::audio::Component> newComp(new eon::audio::Component(this));

    componentList.push_back(newComp);

    return newComp;
}

void eon::audio::Manager::deleteComponent(std::shared_ptr<eon::Component> a_comp) {
    componentList.remove(a_comp);
}