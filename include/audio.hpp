#pragma once

#include <utils.hpp>

namespace eon {
	namespace audio {
		class Component : public eon::Component {
		public:
			void update();
			
			Component() {}
     		~Component() {}
     		Component(const Component &other) {}
		};

		class Manager : public eon::Manager {
		public:
			std::shared_ptr<eon::Component> createComponent();
		};
	}
}