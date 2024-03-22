#pragma once

#include "enums.hpp"

#include <memory>
#include <iostream>

namespace eon {
	class Manager;

    namespace entity {
        class Entity;
    }

    class Component {
	public:
		virtual void update() = 0;

		void print(bool a_entity = false) {
			if (a_entity) {
				std::cout << "\t[INFO][Component]\n\tID: " << id << "\n\t"
					<< "Type: " << getComponentTypeString(type) << "\n";
			}
			else {
				std::cout << "[INFO][Component]\nID: " << id << "\n"
					<< "Type: " << getComponentTypeString(type) << "\n";
			}			
		}

     	virtual ~Component() {}

		ComponentType getType() 
			{ return type; };			
		std::weak_ptr<entity::Entity> getEntity() 
			{ return entity; };
		void setEntity(std::weak_ptr<entity::Entity> a_entity)
			{ entity = a_entity; };

	protected:
		unsigned long long id = 0;
		ComponentType type;
		std::weak_ptr<entity::Entity> entity;
		eon::Manager* manager;
	};
}