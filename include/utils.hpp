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

	class Component {
	public:
		virtual void update() = 0;
		ComponentType getType() {
			return type;
		}

		Component() {}
     	~Component() {}
     	Component(const Component &a_other) {}

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

	// https://stackoverflow.com/questions/8357240/how-to-automatically-convert-strongly-typed-enum-into-int
	template <typename E>
	constexpr auto to_underlying(E a_e) noexcept {
		return static_cast<std::underlying_type_t<E>>(a_e);
	}
}