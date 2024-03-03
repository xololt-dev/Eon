#pragma once

#include "component.hpp"
#include "enums.hpp"

namespace eon {
    namespace controls {
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
    }
}