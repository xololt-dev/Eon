#pragma once

#include <utils.hpp>

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

		class Manager : public eon::Manager {
		public:
			std::shared_ptr<eon::Component> createComponent(ComponentType a_type);
			void deleteComponent(std::shared_ptr<eon::Component> a_comp);
		};
	}
}