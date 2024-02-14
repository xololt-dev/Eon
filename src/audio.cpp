#include <audio.hpp>

void eon::audio::Component::update() {

}

std::shared_ptr<eon::Component> eon::audio::Manager::createComponent() {
    std::shared_ptr<eon::audio::Component> newComp(new eon::audio::Component()); // = new eon::controls::PlayerComponent();

    componentList.push_back(std::move(newComp));

    return newComp;
}