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

			Component() {
				type = ComponentType::Physics;
			}
     		~Component() {}
     		Component(const Component &a_other) {}

		private:
			std::tuple<short, short> getUserInput();

			glm::vec3 velocity = { 0.0f, 0.0f, 0.0f };			// Velocity
			glm::vec3 acceleration = { 0.0f, 0.0f, 0.0f };		// Acceleration
			float mass = 1.0f;
			RigidBody rigidBody;
		};

		// For physics.cpp getUserInput()
		template<typename _Tp, typename _Up>
		inline std::shared_ptr<_Tp>
		static_pointer_cast(const std::shared_ptr<eon::physics::Component>& __r);

		class Manager : public eon::Manager {
		public:
			std::shared_ptr<eon::Component> createComponent(ComponentType a_type);
			void deleteComponent(std::shared_ptr<eon::Component> a_physics);

		protected:
		};		
	}
}