#pragma once

#include <utils.hpp>

#include <iostream>
#include <vector>
#include <list>

namespace eon {
	namespace entity {
		enum class EntityType {
			Player,
			Computer,
			Dynamic,
			Static
		};

		class Entity {
		public:
			Entity(unsigned int a_id) :
				id(a_id) {}

			virtual void displayID() {
				std::cout << "Entity ID: " << id << "\n";
			};

			bool addComponent(Component& a_component);

		protected:
			unsigned int id = 0;
			EntityType type;
			glm::vec3 position = { 0.0f, 0.0f, 0.0f };

			std::list<Component> componentsList;
		};

		class EntityManager {
		public:

		protected:
			std::vector<Entity> entitiesList;
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