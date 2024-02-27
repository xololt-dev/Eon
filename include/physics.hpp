#pragma once

#include <utils.hpp>

#include "glm/fwd.hpp"
#include "glm/glm.hpp"

#include <chrono>
#include <memory>

namespace eon {
	namespace entity {
		class Entity;
	}
	namespace physics {
		class RigidBody {

		};

		class CollisionCommand : public eon::Command {

		};

		class DisplacementCommand : public eon::Command {
		public:
			void execute();

			DisplacementCommand(glm::vec3 a_displacement, 
				std::shared_ptr<eon::entity::Entity> a_srcEntity) :
				displacement(a_displacement) {
					srcEntity = a_srcEntity;
			}
			~DisplacementCommand() {}
			DisplacementCommand(const DisplacementCommand& a_other) {}

		protected:
			glm::vec3 displacement = { 0.0f, 0.0f, 0.0f };
		};
		
		// TODO: Component and Manager
		class Component : public eon::Component {
		public:
			void update();
			void includeMovement(glm::vec3 a_movement) 
				{ velocity += a_movement; }

			Component() {
				type = ComponentType::Physics;
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
			RigidBody rigidBody;
		};

		// For physics.cpp getUserInput()
		/*
		template<typename _Tp, typename _Up>
		inline std::shared_ptr<_Tp>
		static_pointer_cast(const std::shared_ptr<eon::physics::Component>& __r);

		template<typename _Tp, typename _Up>
		inline std::weak_ptr<_Tp>
		static_pointer_cast(const std::weak_ptr<eon::physics::Component>& __r);
*/
		class Manager : public eon::Manager {
		public:
			std::shared_ptr<eon::Component> createComponent(ComponentType a_type);
			void deleteComponent(std::shared_ptr<eon::Component> a_physics);

		protected:
		};		
	}
}