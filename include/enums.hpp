#pragma once

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
}