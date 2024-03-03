#pragma once

#include "SDL_keycode.h"

#include "manager.hpp"
#include "enums.hpp"

#include <map>

namespace eon {
    namespace controls {
        class Manager : public eon::Manager {
		public:
			void update();
			std::shared_ptr<eon::Component> createComponent(ComponentType a_type);
			void deleteComponent(std::shared_ptr<eon::Component> a_comp);
			std::tuple<short, short> getAxisMovement();

			void updateKeybinds();

			Manager() {
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