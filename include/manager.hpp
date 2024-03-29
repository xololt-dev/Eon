#pragma once

#include "component.hpp"
#include "command.hpp"

#include <list>
#include <iostream>
namespace eon {
	class SystemsManager;

    class Manager {
	public:
		void update();

		virtual std::shared_ptr<eon::Component> createComponent(ComponentType a_type) = 0;
		virtual void deleteComponent(std::shared_ptr<Component> a_component) = 0;

		void addCommand(const std::shared_ptr<eon::Command>& a_command) 
			{ commandsPending.push_back(a_command); std::cout << "addCommand Manager\n";}
		void sendCommand(const std::shared_ptr<eon::Command>& a_command);

		virtual ~Manager() {}

		size_t getComponentsAmount()
			{ return componentList.size(); };

		void setSystemsManager(SystemsManager* a_sysManager) 
			{ systemsManager = a_sysManager;
			std::cout << &*systemsManager << "\n"; };

	protected:
		SystemsManager* systemsManager;
		std::list<std::shared_ptr<Component>> componentList; 	// In future vector, list now for simplicity
		std::list<std::shared_ptr<Command>> commandsPending;	// Same as above
	};
}