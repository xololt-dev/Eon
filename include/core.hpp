#pragma once

#include <controls/controls.hpp>
#include <physics/physics.hpp>
#include <entity/entity.hpp>
#include <audio/audio.hpp>
#include <render/render.hpp>

namespace eon {
	class Engine {
	public:
		void gameLoop();

	protected:
		// SystemsManager systemManager;
	};
}