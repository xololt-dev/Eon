#pragma once

#include "glm/fwd.hpp"

#include "entity.hpp"
#include "command.hpp"

#include <memory>

namespace eon {
    class SystemsManager;

	namespace entity {
        class Manager {
        public:
            void update();

            std::shared_ptr<eon::entity::Entity> addEntity(
                unsigned long long a_id, EntityType a_type = EntityType::Null, 
                glm::vec3 a_position = { 0.0f, 0.0f, 0.0f });
            void addEntities();
            void deleteEntity();

            void addComponent(std::shared_ptr<eon::Component> a_component, unsigned long long a_id);
            
            void addCommand(std::shared_ptr<eon::Command>& a_command) 
                { commandsPending.push_back(a_command); }
            void sendCommand(std::shared_ptr<eon::Command>& a_command);

            void setSystemsManager(SystemsManager* a_sysManager) 
                { systemsManager = a_sysManager; };
            
            size_t getEntitiesAmount()
                { return entitiesList.size(); };

        protected:
            SystemsManager* systemsManager;
            std::list<std::shared_ptr<Entity>> entitiesList; 		// In future vector, list now for simplicity
            std::list<std::shared_ptr<Command>> commandsPending;	// Same as above
        };
    }
}