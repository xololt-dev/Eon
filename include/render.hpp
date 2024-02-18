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

		template<typename _Tp, typename _Up>
		inline std::shared_ptr<_Tp>
		static_pointer_cast(const std::shared_ptr<eon::render::Component>& __r);

		class Manager : public eon::Manager {
		public:
			std::shared_ptr<eon::Component> createComponent(ComponentType a_type);
			void deleteComponent(std::shared_ptr<eon::Component> a_comp);
		};
	}
}