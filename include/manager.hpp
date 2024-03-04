#pragma once

#include "component.hpp"
#include "command.hpp"

#include <list>

namespace eon {
	class SystemsManager;

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

		void setSystemsManager(SystemsManager* a_sysManager) 
			{ systemsManager = a_sysManager; };

	protected:
		SystemsManager* systemsManager;
		std::list<std::shared_ptr<Component>> componentList; 	// In future vector, list now for simplicity
		std::list<std::shared_ptr<Command>> commandsPending;	// Same as above
	};
}