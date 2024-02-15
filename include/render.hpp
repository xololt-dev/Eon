#pragma once

#include <utils.hpp>

namespace eon {
	namespace render {
		class Component : public eon::Component {
		public:
			void update();

			Component() {
				type = ComponentType::Render;
			}
     		~Component() {}
     		Component(const Component &a_other) {}
		};

		class Manager : public eon::Manager {
		public:
			std::shared_ptr<eon::Component> createComponent(ComponentType a_type);
		};
	}
}