#pragma once

#include "glm/fwd.hpp"
#include "glm/glm.hpp"

#include <utils.hpp>

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
				
				for (auto comp : a_components)
					componentsList.push_back(std::move(comp));
			}

			// TODO: Destructor, copy constructor, copy assignment operator

			void displayID() {
				std::cout << "Entity ID: " << id << "\n";
			};

			bool addComponent(std::shared_ptr<Component> a_component);

		protected:
			unsigned int id = 0;
			EntityType type;
			glm::vec3 position = { 0.0f, 0.0f, 0.0f };

			std::list<std::shared_ptr<Component>> componentsList;
		};

		class Manager {
		public:
			void addEntity();
			void addEntities();
			void deleteEntity();

			size_t getEntitiesAmount()
				{ return entitiesList.size(); };

		protected:
			std::list<Entity> entitiesList; // In future vector, list now for simplicity
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