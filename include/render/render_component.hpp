#pragma once

#include "component.hpp"

namespace eon {
    namespace render {
        class Component : public eon::Component {
		public:
			// virtual void update() = 0;

			Component() {
				type = ComponentType::Render;
			}
     		~Component() {}
     		Component(const Component &a_other) {}
		};
    }
}