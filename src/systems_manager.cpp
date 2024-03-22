#include "render/render_draw_color_command.hpp"
#include <systems_manager.hpp>

#include <memory>

std::atomic_ullong eon::SystemsManager::nextID{0};

void eon::SystemsManager::update() {
    std::cout << "PreControls update\n";
    controls->update();
    std::cout << "PostControls update\n";
    std::cout << "PrePhysics update\n";
    physics->update();
    std::cout << "PostPhysics update\n";
    std::cout << "PreEntity update\n";
    entities->update();
    std::cout << "PostEntity update\n";
    std::cout << "PreRender update\n";
    render->update();
    std::cout << "PostRender update\n";

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

unsigned long long eon::SystemsManager::createEntity(unsigned long long a_id, 
    entity::EntityType a_type, glm::vec3 a_position) {
    entities->addEntity(a_id, a_type, a_position);

    return a_id;
}

std::shared_ptr<eon::Component> eon::SystemsManager::createComponent(ComponentType a_type) {
    std::shared_ptr<Component> returnPtr;
    
    switch (a_type) {
        case ComponentType::Player:
        case ComponentType::Computer:
            return controls->createComponent(a_type);
            break;
        case ComponentType::Physics:
            return physics->createComponent(a_type);
            break;
        case ComponentType::Render:
            return render->createComponent(a_type);
            break;
        case ComponentType::Audio:
            return audio->createComponent(a_type);
            break;
    }
}

std::shared_ptr<eon::Component> eon::SystemsManager::createComponent(ComponentType a_type, unsigned long long a_id) {
    std::shared_ptr<Component> returnPtr;
    
    switch (a_type) {
        case ComponentType::Player:
        case ComponentType::Computer:
            returnPtr = controls->createComponent(a_type);
            break;
        case ComponentType::Physics:
            returnPtr = physics->createComponent(a_type);
            break;
        case ComponentType::Render:
            returnPtr = render->createComponent(a_type);
            break;
        case ComponentType::Audio:
            returnPtr = audio->createComponent(a_type);
            break;
    }

    if (returnPtr != nullptr)
        entities->addComponent(returnPtr, a_id);

    return returnPtr;
}

void eon::SystemsManager::deleteComponent(std::shared_ptr<controls::PlayerComponent> a_player) {
    controls->deleteComponent(a_player);
}

void eon::SystemsManager::deleteComponent(std::shared_ptr<controls::AIComponent> a_computer) {
    controls->deleteComponent(a_computer);
}

void eon::SystemsManager::deleteComponent(std::shared_ptr<physics::Component> a_physics) {
    physics->deleteComponent(a_physics);
}

void eon::SystemsManager::deleteComponent(std::shared_ptr<audio::Component> a_audio) {
    audio->deleteComponent(a_audio);
}

void eon::SystemsManager::deleteComponent(std::shared_ptr<render::Component> a_render) {
    render->deleteComponent(a_render);
}

void eon::SystemsManager::sendCommand(const std::shared_ptr<Command>& a_command) {
    std::cout << "SystemsManager sendCommand" << a_command.use_count() << "\n";
    CommandType currentType = a_command->getType();

    switch (currentType) {
        case CommandType::Movement:
            physics->addCommand(a_command);
            break;
        case CommandType::Collision:
        case CommandType::Displacement:
            entities->addCommand(a_command);
            break;
        case CommandType::RenderDrawColorCommand:
            std::static_pointer_cast<eon::render::RenderDrawColorCommand>(a_command)
                ->setManager(*render.get());
            render->addCommand(a_command);
            break;
        }
}