#pragma once

#include <cstddef>
#include <list>
#include <memory>
#include <type_traits>

namespace eon {
	enum class ComponentType {
		Player,
		Computer,
		Physics,
		Render,
		Audio
	};
	namespace entity {
		class Entity;
	}

	class Component {
	public:
		virtual void update() = 0;

		Component() {}
     	~Component() {}
     	Component(const Component &a_other) {}

		ComponentType getType() 
			{ return type; }
		std::weak_ptr<entity::Entity> getEntity() 
			{ return entity; }

		void setEntity(std::weak_ptr<entity::Entity> a_entity)
			{ entity = a_entity; };

	protected:
		ComponentType type;
		std::weak_ptr<entity::Entity> entity;
	};

	class Manager {
	public:
		void update();
		virtual std::shared_ptr<eon::Component> createComponent(ComponentType a_type) = 0;
		virtual void deleteComponent(std::shared_ptr<Component> a_component) = 0;

		size_t getEntitiesAmount()
				{ return componentList.size(); };
	protected:
		std::list<std::shared_ptr<Component>> componentList; // In future vector, list now for simplicity
	};

	// https://stackoverflow.com/questions/8357240/how-to-automatically-convert-strongly-typed-enum-into-int
	template <typename E>
	constexpr auto to_underlying(E a_e) noexcept {
		return static_cast<std::underlying_type_t<E>>(a_e);
	}
}