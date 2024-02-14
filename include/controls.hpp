#pragma once

#include <utils.hpp>

#include <tuple>

namespace eon {
	namespace controls {
		// TODO: PlayerComponent and controls::Manager 
		class PlayerComponent : public eon::Component {
		public:
			void update();
			std::tuple<short, short> getAxisMovement() {
				return std::make_tuple(xAxis, yAxis);
			}

			PlayerComponent() {}
     		~PlayerComponent() {}
     		PlayerComponent(const PlayerComponent &other) {}

		protected:
			ComponentType type = ComponentType::Player;
			short xAxis = 0;
			short yAxis = 0;
		};

		class AIComponent : public eon::Component {
		protected:
			ComponentType type = ComponentType::Computer;
		};

		class Manager : public eon::Manager {
		public:
			void update();

			std::shared_ptr<eon::Component> createComponent();
		};
	}
}