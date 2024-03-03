#pragma once

#include <glm/glm.hpp>

#include "controls/player_component.hpp"
#include "controls/ai_component.hpp"
#include "audio/audio_component.hpp"
#include "physics/physics_component.hpp"
#include "render/render_component.hpp"

#include "entity_type.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <memory>

namespace eon {
	namespace entity {
		class Entity {
		public:
			// Basic Entity constructor
			Entity(unsigned int a_id, EntityType a_type = EntityType::Null, 
				glm::vec3 a_position = { 0.0f, 0.0f, 0.0f }) :
				id(a_id), type(a_type), position(a_position) 
				{}

			// Entity constructor with components
			Entity(unsigned int a_id, EntityType a_type, glm::vec3 a_position, 
				std::vector<std::shared_ptr<Component>>& a_components) :
				id(a_id), type(a_type), position(a_position) {
				
				for (std::shared_ptr<Component>& comp : a_components)
					componentsList.push_back(std::move(comp));
			}

			// TODO: Destructor, copy constructor, copy assignment operator
			~Entity() {}
     		Entity(const Entity &a_other) {}

			void displayID() {
				std::cout << "Entity ID: " << id << "\n";
			};

			void addComponent(std::shared_ptr<eon::controls::PlayerComponent> a_component, ComponentType a_type)
				{ componentsList.push_back(a_component); };
			void addComponent(std::shared_ptr<eon::controls::AIComponent> a_component, ComponentType a_type)
				{ componentsList.push_back(a_component); };
			void addComponent(std::shared_ptr<eon::physics::Component> a_component, ComponentType a_type)
				{ componentsList.push_back(a_component); };
			void addComponent(std::shared_ptr<eon::audio::Component> a_component, ComponentType a_type)
				{ componentsList.push_back(a_component); };
			void addComponent(std::shared_ptr<eon::render::Component> a_component, ComponentType a_type)
				{ componentsList.push_back(a_component); };
			std::shared_ptr<Component> getComponent(ComponentType a_type);
			unsigned int getId()
				{ return id; };
			void setType(EntityType a_type)
				{ type = a_type; };
			EntityType getType()
				{ return type; };
			void setPosition(glm::vec3 a_pos)
				{ position = a_pos; };
			void offsetPosition(glm::vec3 a_offset) 
				{ position += a_offset; };
			glm::vec3 getPosition()
				{ return position; };

		protected:
			unsigned int id = 0;
			EntityType type;
			glm::vec3 position = { 0.0f, 0.0f, 0.0f };

			std::list<std::shared_ptr<Component>> componentsList;
		};
	}
}