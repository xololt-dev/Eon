#pragma once

#include <controls.hpp>
#include <physics.hpp>
#include <entity.hpp>
#include <audio.hpp>
#include <render.hpp>
#include <utils.hpp>

namespace eon {
	class SystemsManager {
	public:
		void update();

	protected:
		controls::Manager controls;
		physics::Manager physics;
		audio::Manager audio;
		render::Manager render;
		entity::Manager entities;
	};

	class Engine {
	public:
		void gameLoop();

	protected:
		SystemsManager systemManager;
	};
}