#include <systems_manager.hpp>

#include <memory>
#include <tuple>

void eon::SystemsManager::update() {
    controls.update();
    std::tuple<short, short> t = controls.getAxisMovement();
    
    if (std::get<0>(t) == 0) {
        if (std::get<1>(t) == 0) {
            // render.setRenderDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
        }
        else if (std::get<1>(t) > 0) {
            render.setRenderDrawColor(0xFF, 0x00, 0x00, 0xFF);
        }
        else {
            render.setRenderDrawColor(0x00, 0xFF, 0x00, 0xFF);
        }
    }
    else if (std::get<0>(t) > 0) {
        if (std::get<1>(t) == 0) {
            render.setRenderDrawColor(0xFF, 0xA5, 0x00, 0xFF);
        }
        else if (std::get<1>(t) > 0) {
            render.setRenderDrawColor(0xFF, 0x8C, 0x00, 0xFF);
        }
        else {
            render.setRenderDrawColor(0xFF, 0xFF, 0x00, 0xFF);
        }
    }
    else {
        if (std::get<1>(t) == 0) {
            render.setRenderDrawColor(0x00, 0x00, 0x7F, 0xFF);
        }
        else if (std::get<1>(t) > 0) {
            render.setRenderDrawColor(0x7F, 0x00, 0x7F, 0xFF);
        }
        else {
            render.setRenderDrawColor(0x00, 0xFF, 0xFF, 0xFF);
        }
    }

    render.update();

    /*
    // Update entities - probably beginning (think about intermediate update) 

    // Atleast at the beginning & potential for each/once every x physics updates 
    controls.update();
    // Atleast once & can get looped
    physics.update();
    // Most likely once is enough (I mean... audio update every ~16 - 33ms is pretty dang good already)
    audio.update();
    // Once - maybe alternate inside update function between different types
    render.update();
    */
}

std::shared_ptr<eon::Component> eon::SystemsManager::createComponent(ComponentType a_type) {
    std::shared_ptr<Component> returnPtr;
    
    switch (a_type) {
        case ComponentType::Player:
        case ComponentType::Computer:
            return controls.createComponent(a_type);
            break;
        case ComponentType::Physics:
            return physics.createComponent(a_type);
            break;
        case ComponentType::Render:
            return render.createComponent(a_type);
            break;
        case ComponentType::Audio:
            return audio.createComponent(a_type);
            break;
    }
}

void eon::SystemsManager::deleteComponent(std::shared_ptr<controls::PlayerComponent> a_player) {
    controls.deleteComponent(a_player);
}

void eon::SystemsManager::deleteComponent(std::shared_ptr<controls::AIComponent> a_computer) {
    controls.deleteComponent(a_computer);
}

void eon::SystemsManager::deleteComponent(std::shared_ptr<physics::Component> a_physics) {
    physics.deleteComponent(a_physics);
}

void eon::SystemsManager::deleteComponent(std::shared_ptr<audio::Component> a_audio) {
    audio.deleteComponent(a_audio);
}

void eon::SystemsManager::deleteComponent(std::shared_ptr<render::Component> a_render) {
    render.deleteComponent(a_render);
}

void eon::SystemsManager::sendCommand(std::shared_ptr<Command>& a_command) {
    CommandType currentType = a_command->getType();

    switch (currentType) {
        case CommandType::Movement:
            physics.addCommand(a_command);
            break;
        case CommandType::Collision:
        case CommandType::Displacement:
            entities->addCommand(a_command);
            break;
    }
}