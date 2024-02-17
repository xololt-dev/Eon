#include <audio.hpp>

void eon::audio::Component::update() {

}

std::shared_ptr<eon::Component> eon::audio::Manager::createComponent(ComponentType a_type) {
    std::shared_ptr<eon::audio::Component> newComp(new eon::audio::Component()); // = new eon::controls::PlayerComponent();

    componentList.push_back(std::move(newComp));

    return newComp;
}

void eon::audio::Manager::deleteComponent(std::shared_ptr<eon::Component> a_comp) {
    componentList.remove(a_comp);
}