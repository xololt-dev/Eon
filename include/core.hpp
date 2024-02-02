#pragma once

#include <iostream>
#include <vector>

#include <glm/glm.hpp>

namespace eon {
	class Component {
	public:
		int somthing;
	};

	class Entity {
	public:
		Entity(int _id) :
			id(_id) {}

		virtual void displayID()
		{
			std::cout << "Entity ID: " << id << "\n";
		};

	protected:
		int id = 0;
		glm::vec3 position = { 0.0f, 0.0f, 0.0f };

		std::vector<Component> componentsList;
	};

	class Manager {

	};

	class SystemsManager {

	};
}