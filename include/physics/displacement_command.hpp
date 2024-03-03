#pragma once

#include <glm/glm.hpp>

#include "command.hpp"

#include <memory>

namespace eon {
	namespace entity {
	    class Entity;
	}

	namespace physics {
        class DisplacementCommand : public eon::Command {
		public:
			void execute();

			DisplacementCommand(glm::vec3 a_displacement, 
				std::weak_ptr<eon::entity::Entity> a_srcEntity) :
				displacement(a_displacement) {
					srcEntity = a_srcEntity;
			}
			~DisplacementCommand() {}
			DisplacementCommand(const DisplacementCommand& a_other) {}

		protected:
			glm::vec3 displacement = { 0.0f, 0.0f, 0.0f };
		};
    }
}
