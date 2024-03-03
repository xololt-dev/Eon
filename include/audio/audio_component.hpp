#pragma once

#include "component.hpp"
#include "enums.hpp"

namespace eon {
	namespace audio {
		class Component : public eon::Component {
		public:
			void update();
			
			Component() {
				type = ComponentType::Audio;
			}
     		~Component() {}
     		Component(const Component &a_other) {}
		};
    }
}