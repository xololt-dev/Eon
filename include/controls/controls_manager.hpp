#pragma once

// #include "SDL_keycode.h"

#include <SDL2/SDL_keycode.h>

#include "manager.hpp"
#include "enums.hpp"

#include <map>
#include <iostream>

namespace eon {
    namespace controls {
        class Manager : public eon::Manager {
		public:
			void update();
			std::shared_ptr<eon::Component> createComponent(ComponentType a_type);
			void deleteComponent(std::shared_ptr<eon::Component> a_comp);
			std::tuple<short, short> getAxisMovement();

			void updateKeybinds();

			// void sendCommand(std::shared_ptr<eon::Command>& a_command);

			Manager() {
				std::cout << "[INFO] Created ControlsManager\n";
				loadKeybinds();
			}
			Manager(SystemsManager& a_sysManager) {
				std::cout << "[INFO] Created ControlsManager\n";
				setSystemsManager(&a_sysManager);
				loadKeybinds();
			}
			~Manager() {}
			Manager(const Manager &a_other) {}

			bool getQuit()
				{ return quit; }
			
		protected:
			// TODO: setting keybinds via file 
			std::map<SDL_Keycode, int> keyMap;
			bool quit = false;

			void loadKeybinds();
		};
    }
}