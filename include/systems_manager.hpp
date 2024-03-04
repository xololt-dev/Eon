#pragma once

#include "component.hpp"
#include "controls/controls_manager.hpp"
#include "controls/player_component.hpp"
#include "controls/ai_component.hpp"
#include "physics/physics_manager.hpp"
#include "physics/physics_component.hpp"
#include "entity/entity_manager.hpp"
#include "entity/entity_type.hpp"
#include "audio/audio_manager.hpp"
#include "render/render_manager.hpp"

#include <memory>
#include <atomic>
#include <vector>

namespace eon {
    class Component;
	enum class ComponentType;

    class SystemsManager {
	public:
		void update();

		unsigned long long createEntity(unsigned long long a_id, 
			entity::EntityType a_type = entity::EntityType::Null, 
			glm::vec3 a_position = { 0.0f, 0.0f, 0.0f });
		
		std::shared_ptr<Component> createComponent(ComponentType a_type);

		void deleteComponent(std::shared_ptr<controls::PlayerComponent> a_player);
		void deleteComponent(std::shared_ptr<controls::AIComponent> a_computer);
		void deleteComponent(std::shared_ptr<physics::Component> a_physics);
		void deleteComponent(std::shared_ptr<audio::Component> a_audio);
		void deleteComponent(std::shared_ptr<render::Component> a_render);

		void sendCommand(std::shared_ptr<Command>& a_command);

		SystemsManager() {
			// NOTE: For now entities manager is a special case - potential TODO
			entities.setSystemsManager(this);

			std::vector<eon::Manager*> managers = {&controls, &physics, &audio, &render};
			for (eon::Manager* m : managers)
				m->setSystemsManager(this);
		}

		bool getQuit()
			{ return controls.getQuit(); };
		unsigned long long getNextID()
			{ return nextID++; };

	protected:
		static std::atomic_ullong nextID;							// Do we wanna use "slug"s too? (human-readable, unique identifier)
		
		controls::Manager controls;
		physics::Manager physics;
		audio::Manager audio;
		render::Manager render;
		entity::Manager entities;
	};
}
