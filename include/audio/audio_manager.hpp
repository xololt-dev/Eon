#pragma once

#include "manager.hpp"

#include <memory>
#include <iostream>

namespace eon {
    namespace audio {
        class Manager : public eon::Manager {
		public:
			std::shared_ptr<eon::Component> createComponent(ComponentType a_type);
			void deleteComponent(std::shared_ptr<eon::Component> a_comp);

			Manager(SystemsManager& a_sysManager) {
				std::cout << "[INFO] Created AudioManager\n";
				setSystemsManager(&a_sysManager);
				std::cout << systemsManager << "\n";
			}
		};
    }
}