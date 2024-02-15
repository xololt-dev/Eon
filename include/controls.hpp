#pragma once

#include "SDL_keycode.h"
#include <utils.hpp>

#include <tuple>
#include <map>

namespace eon {
	namespace controls {
		enum class GameKeyActions {
			Up,
			Down,
			Left,
			Right
		};

		// TODO: PlayerComponent and controls::Manager 
		class PlayerComponent : public eon::Component {
		public:
			void update();
			std::tuple<short, short> getAxisMovement() 
				{ return std::make_tuple(xAxis, yAxis); }

			PlayerComponent() {
				type = ComponentType::Player;
			}
     		~PlayerComponent() {}
     		PlayerComponent(const PlayerComponent &a_other) {}

		protected:
			short xAxis = 0;
			short yAxis = 0;
		};

		class AIComponent : public eon::Component {
		public:
			AIComponent() {
				type = ComponentType::Computer;
			}
     		~AIComponent() {}
     		AIComponent(const AIComponent &a_other) {}

		protected:
		};

		class Manager : public eon::Manager {
		public:
			void update();
			std::shared_ptr<eon::Component> createComponent();

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