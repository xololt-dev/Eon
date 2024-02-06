#pragma once

#include <iostream>
#include <vector>

#include <controls.hpp>
#include <physics.hpp>
#include <entity.hpp>
#include <audio.hpp>
#include <render.hpp>

#include <glm/glm.hpp>

namespace eon {
	class SystemsManager {
	public:
		void update();

	protected:
		controls::ControlsManager controls;
		physics::PhysicsManager physics;
		audio::AudioManager audio;
		render::RenderManager render;
		entity::EntityManager entities;
	};

	class Engine {
	public:

	protected:
		SystemsManager systemManager;
	};
}