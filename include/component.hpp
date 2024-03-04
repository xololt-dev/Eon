#pragma once

#include "enums.hpp"

#include <memory>

namespace eon {
	class Manager;

    namespace entity {
        class Entity;
    }

    class Component {
	public:
		virtual void update() = 0;

		Component() {}
     	virtual ~Component() {}
     	Component(const Component& a_other) {}

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
		std::weak_ptr<eon::Manager> manager;
	};
}