#pragma once

#include "component.hpp"
#include "enums.hpp"
#include "audio/audio_manager.hpp"

namespace eon {
	namespace audio {
		class Component : public eon::Component {
		public:
			void update();
			
			Component(audio::Manager* a_manager) {
				type = ComponentType::Audio;
				manager = a_manager;
			}
     		~Component() {}
     		Component(const Component &a_other) {}
		};
    }
}