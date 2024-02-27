#pragma once

#include <controls.hpp>
#include <physics.hpp>
#include <entity.hpp>
#include <audio.hpp>
#include <render.hpp>

namespace eon {
	class Engine {
	public:
		void gameLoop();

	protected:
		// SystemsManager systemManager;
	};
}