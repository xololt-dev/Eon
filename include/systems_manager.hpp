#pragma once

#include <controls.hpp>
#include <physics.hpp>
#include <entity.hpp>
#include <audio.hpp>
#include <render.hpp>

#include <memory>

namespace eon {
    class Component;
	enum class ComponentType;

    class SystemsManager {
	public:
		void update();
		std::shared_ptr<Component> createComponent(ComponentType a_type);

		void deleteComponent(std::shared_ptr<controls::PlayerComponent> a_player);
		void deleteComponent(std::shared_ptr<controls::AIComponent> a_computer);
		void deleteComponent(std::shared_ptr<physics::Component> a_physics);
		void deleteComponent(std::shared_ptr<audio::Component> a_audio);
		void deleteComponent(std::shared_ptr<render::Component> a_render);

		bool getQuit()
			{ return controls.getQuit(); };

	protected:
		controls::Manager controls;
		physics::Manager physics;
		audio::Manager audio;
		render::Manager render;
		entity::Manager entities;
	};
}