#pragma once

#include "glm/detail/qualifier.hpp"
#include "glm/fwd.hpp"
#include "glm/glm.hpp"

#include "controls.hpp"
#include "audio.hpp"
#include <utils.hpp>
#include "physics.hpp"
#include "render.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <memory>

namespace eon {
	namespace entity {
		enum class EntityType {
			Null,
			Player,
			Computer,
			DynamicAudio,
			Dynamic,
			StaticAudio,
			Static,
			Other			
		};

		class Entity {
		public:
			// Basic Entity constructor
			Entity(unsigned int a_id, EntityType a_type = EntityType::Null, 
				glm::vec3 a_position = { 0.0f, 0.0f, 0.0f }) :
				id(a_id), type(a_type), position(a_position) 
				{}

			// Entity constructor with components
			Entity(unsigned int a_id, EntityType a_type, glm::vec3 a_position, 
				std::vector<std::shared_ptr<Component>> a_components) :
				id(a_id), type(a_type), position(a_position) {
				
				for (std::shared_ptr<Component> comp : a_components)
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
			std::weak_ptr<Component> getComponent(ComponentType a_type);
			unsigned int getId()
				{ return id; };
			void setType(EntityType a_type)
				{ type = a_type; };
			EntityType getType()
				{ return type; };
			void setPosition(glm::vec3 a_pos)
				{ position = a_pos; };
			glm::vec3 getPosition()
				{ return position; };

		protected:
			unsigned int id = 0;
			EntityType type;
			glm::vec3 position = { 0.0f, 0.0f, 0.0f };

			std::list<std::shared_ptr<Component>> componentsList;
		};

		class Manager {
		public:
			std::shared_ptr<eon::entity::Entity> addEntity(
				unsigned int a_id, EntityType a_type = EntityType::Null, 
				glm::vec3 a_position = { 0.0f, 0.0f, 0.0f });
			void addEntities();
			void deleteEntity();

			size_t getEntitiesAmount()
				{ return entitiesList.size(); };

		protected:
			std::list<std::shared_ptr<Entity>> entitiesList; // In future vector, list now for simplicity
		};
	}
	/*
	class PhysicsEntity : public Entity {
	public:
		PhysicsEntity (int _id) :
			Entity(_id) {}

		void displayID() 
			{ std::cout << "PhysicsEntity ID: " << id << "\n"; };

	protected:
		// physics
	};

	class Player : public PhysicsEntity {
	public:
		Player (int _id) :
			PhysicsEntity (_id) {}

		void displayID() 
			{ std::cout << "Player ID: " << id << "\n"; };

	private:
		// player input
	};

	class Zombie : public PhysicsEntity {
	public:
		Zombie(int _id) :
			PhysicsEntity(_id) {}

		void displayID()
			{ std::cout << "Zombie ID: " << id << "\n"; };
	private:
		// ai imput
	};
	*/
}