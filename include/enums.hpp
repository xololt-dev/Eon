#pragma once

#include <string>

namespace eon {
    enum class ComponentType {
		Player,
		Computer,
		Physics,
		Render,
		Audio
	};

	enum class CommandType {
		Movement,
		Collision,
		Displacement
	};

	static std::string getComponentTypeString(ComponentType a_type) {
		switch (a_type) {
			case ComponentType::Player:
				return "Player";
			case ComponentType::Computer:
				return "Computer";
			case ComponentType::Physics:
				return "Physics";
			case ComponentType::Render:
				return "Render";
			case ComponentType::Audio:
				return "Audio";
		}
	}
}