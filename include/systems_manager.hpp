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
		std::shared_ptr<Component> createComponent(ComponentType a_type, unsigned long long a_id);

		void deleteComponent(std::shared_ptr<controls::PlayerComponent> a_player);
		void deleteComponent(std::shared_ptr<controls::AIComponent> a_computer);
		void deleteComponent(std::shared_ptr<physics::Component> a_physics);
		void deleteComponent(std::shared_ptr<audio::Component> a_audio);
		void deleteComponent(std::shared_ptr<render::Component> a_render);

		void sendCommand(const std::shared_ptr<Command>& a_command);

		void printEntities(bool a_components = false) {
			entities->printEntities(a_components);
		}

		SystemsManager() {
			std::cout << "[INFO] Created SystemsManager\n";
			// NOTE: For now entities manager is a special case - potential TODO
			entities = std::make_unique<entity::Manager>(*this);
			controls = std::make_unique<controls::Manager>(*this);
			physics = std::make_unique<physics::Manager>(*this);
			audio = std::make_unique<audio::Manager>(*this);
			render = std::make_unique<render::Manager>(*this, "Hello Eon", 1280, 720, 
			(SDL_WindowFlags) (SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI));
		}

		bool getQuit()
			{ return controls->getQuit(); };
		unsigned long long getNextID()
			{ return nextID++; };

	protected:
		static std::atomic_ullong nextID;							// Do we wanna use "slug"s too? (human-readable, unique identifier)
		
		std::unique_ptr<controls::Manager> controls;
		std::unique_ptr<physics::Manager> physics;
		std::unique_ptr<audio::Manager> audio;
		std::unique_ptr<render::Manager> render;
		std::unique_ptr<entity::Manager> entities;
	};
}
