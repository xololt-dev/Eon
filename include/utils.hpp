#pragma once

#include <cstddef>
#include <vector>

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

	protected:
		ComponentType type;
	};

	class Manager {
	public:
		size_t getEntitiesAmount()
				{ return componentList.size(); };
	protected:
		std::vector<Component*> componentList;
	};
}