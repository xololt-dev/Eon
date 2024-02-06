#pragma once

#include <glm/glm.hpp>

#include <vector>

namespace eon {
	namespace physics {
		class RigidBody {

		};

		class PhysicsComponent : public Component {
		public:
			void update();

		private:
			glm::vec3 velocity;			// Velocity
			glm::vec3 acceleration;		// Acceleration
			RigidBody rigidBody;
		};

		class PhysicsManager : public Manager {

		};
	}
}