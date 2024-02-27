#pragma once

#include "SDL_keycode.h"

#include <utils.hpp>

#include <tuple>
#include <map>
#include <memory>

namespace eon {
	namespace controls {
		enum class GameKeyActions {
			Up,
			Down,
			Left,
			Right
		};

		class MovementCommand : public eon::Command {
		public:
			void execute();

			MovementCommand(short a_xAxis, short a_yAxis) :
				xAxis(a_xAxis), yAxis(a_yAxis) 
				{}
			MovementCommand(short a_xAxis, short a_yAxis, 
				std::shared_ptr<eon::entity::Entity> a_srcEntity) :
				xAxis(a_xAxis), yAxis(a_yAxis) {
					srcEntity = a_srcEntity;
			}
			~MovementCommand() {}
			MovementCommand(const MovementCommand& a_other) {}

		protected:
			short xAxis = 0,
				  yAxis = 0;
		};

		// TODO: PlayerComponent and controls::Manager 
		class PlayerComponent : public eon::Component {
		public:
			void update();

			PlayerComponent() {
				type = ComponentType::Player;
			}
     		~PlayerComponent() {}
     		PlayerComponent(const PlayerComponent &a_other) {}

			ComponentType getType()
				{ return type; };
			std::tuple<short, short> getAxisMovement() 
				{ return std::make_tuple(xAxis, yAxis); }

		protected:
			short xAxis = 0;
			short yAxis = 0;
		};

		class AIComponent : public eon::Component {
		public:
			void update();

			AIComponent() {
				type = ComponentType::Computer;
			}
     		~AIComponent() {}
     		AIComponent(const AIComponent &a_other) {}

		protected:
		};

		/*
		template<typename _Tp, typename _Up>
		inline std::shared_ptr<_Tp>
		static_pointer_cast(const std::shared_ptr<eon::controls::PlayerComponent>& __r);
		template<typename _Tp, typename _Up>
		inline std::shared_ptr<_Tp>
		static_pointer_cast(const std::shared_ptr<eon::controls::AIComponent>& __r);
		*/

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