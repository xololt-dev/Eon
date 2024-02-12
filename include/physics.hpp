#pragma once

#include <utils.hpp>

#include "glm/glm.hpp"

namespace eon {
	namespace physics {
		class RigidBody {

		};
		// TODO: Component and Manager
		class Component : public eon::Component {
		public:
			void update();

		private:
			glm::vec3 velocity = { 0.0f, 0.0f, 0.0f };			// Velocity
			glm::vec3 acceleration = { 0.0f, 0.0f, 0.0f };		// Acceleration
			RigidBody rigidBody;
		};

		class Manager : public eon::Manager {
		public:
		protected:
		};
	}
}