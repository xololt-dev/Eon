#pragma once

#include <glm/glm.hpp>

#include "component.hpp"
#include "enums.hpp"
#include "physics/physics_manager.hpp"

#include <chrono>

namespace eon {
    namespace physics {
        // TODO: Component and Manager
		class Component : public eon::Component {
		public:
			void update();
			void includeMovement(glm::vec3 a_movement) 
				{ velocity += a_movement; }

			Component(physics::Manager* a_manager) {
				type = ComponentType::Physics;
				manager = a_manager;
			}
     		~Component() {}
     		Component(const Component &a_other) {}

			void setElapsed(std::chrono::duration<double> a_elapsed) 
				{ elapsed = a_elapsed; }

		private:
			std::tuple<short, short> getUserInput();

			glm::vec3 velocity = { 0.0f, 0.0f, 0.0f };			// Velocity
			glm::vec3 acceleration = { 0.0f, 0.0f, 0.0f };		// Acceleration
			float mass = 1.0f;
			std::chrono::duration<double> elapsed = std::chrono::seconds(0);
		};
    }
}