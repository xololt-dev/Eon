#pragma once

#include "SDL_surface.h"

#include <cstddef>
#include <list>
#include <memory>
#include <type_traits>
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

	namespace entity {
		class Entity;
	}

	class Manager;
	class SystemsManager;

	class Component {
	public:
		virtual void update() = 0;

		Component() {}
     	virtual ~Component() {}
     	Component(const Component& a_other) {}

		ComponentType getType() 
			{ return type; };			
		std::weak_ptr<entity::Entity> getEntity() 
			{ return entity; };
		void setEntity(std::weak_ptr<entity::Entity> a_entity)
			{ entity = a_entity; };

	protected:
		unsigned int id = 0;
		ComponentType type;
		std::weak_ptr<entity::Entity> entity;
		std::weak_ptr<Manager> manager;
	};

	class Command {
	public:
		virtual void execute() = 0;
		// virtual void undo() {};

		virtual ~Command() {}

	protected:
		std::shared_ptr<eon::entity::Entity> srcEntity;
	};

	class Manager {
	public:
		void update();
		virtual std::shared_ptr<eon::Component> createComponent(ComponentType a_type) = 0;
		virtual void deleteComponent(std::shared_ptr<Component> a_component) = 0;
		void addCommand(std::shared_ptr<eon::Command>& a_command) 
			{ commandsPending.push_back(a_command); }
		void sendCommand(std::shared_ptr<eon::Command>& a_command);

		virtual ~Manager() {}

		size_t getComponentsAmount()
			{ return componentList.size(); };

	protected:
		std::shared_ptr<SystemsManager> systemsManager;
		std::list<std::shared_ptr<Component>> componentList; 	// In future vector, list now for simplicity
		std::list<std::shared_ptr<Command>> commandsPending;	// Same as above
	};

	// https://stackoverflow.com/questions/8357240/how-to-automatically-convert-strongly-typed-enum-into-int
	template <typename E>
	constexpr auto to_underlying(E a_e) noexcept {
		return static_cast<std::underlying_type_t<E>>(a_e);
	}

	class Texture {
	public:
		virtual void load(std::string a_path) = 0;
		virtual void free() = 0;

		virtual ~Texture() {}

	protected:
		std::unique_ptr<SDL_Surface> surface; 
	};

	class PNGTexture : public Texture {
	public:
		void load(std::string a_path);
		void free() {
			if (surface)
				SDL_FreeSurface(surface.get());
		}

		PNGTexture(std::string a_path) 
			{ load(a_path); }
		~PNGTexture() 
			{ free(); }
		PNGTexture(const PNGTexture& a_other) {}
	};

	// TODO: JPEGXL implementation
	class JPEGXLTexture : public Texture {

	};
}