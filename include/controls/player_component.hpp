#pragma once

#include "component.hpp"
#include "enums.hpp"

#include <tuple>

namespace eon {
    namespace controls {
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
    }
}
