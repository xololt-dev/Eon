#pragma once

#include "component.hpp"
#include "controls/controls_manager.hpp"
#include "controls/player_component.hpp"
#include "controls/ai_component.hpp"
#include "physics/physics_manager.hpp"
#include "physics/physics_component.hpp"
#include "entity/entity_manager.hpp"
#include "audio/audio_manager.hpp"
#include "render/render_manager.hpp"

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

		void sendCommand(std::shared_ptr<Command>& a_command);

		SystemsManager() {
			entities = std::make_unique<entity::Manager>(this);
		}

		bool getQuit()
			{ return controls.getQuit(); };

	protected:
		controls::Manager controls;
		physics::Manager physics;
		audio::Manager audio;
		render::Manager render;
		std::unique_ptr<entity::Manager> entities;
	};
}