#pragma once

#include <cstddef>
#include <list>
#include <memory>
namespace eon {
	enum class ComponentType {
		Player,
		Computer,
		Physics,
		Render,
		Audio
	};

	class Component {
	public:
		virtual void update() = 0;
		ComponentType getType() {
			return type;
		}

		Component() {}
     	~Component() {}
     	Component(const Component &other) {}

	protected:
		ComponentType type;
	};

	class Manager {
	public:
		virtual std::shared_ptr<eon::Component> createComponent() = 0;
		void update();

		size_t getEntitiesAmount()
				{ return componentList.size(); };
	protected:
		std::list<std::shared_ptr<Component>> componentList; // In future vector, list now for simplicity
	};
}