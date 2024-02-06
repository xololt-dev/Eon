#pragma once

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

	protected:
		std::vector<Component> componentList;
	};
}