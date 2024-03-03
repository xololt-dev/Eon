#pragma once

#include "command.hpp"

#include <memory>

namespace eon {
    namespace controls {
        class MovementCommand : public eon::Command {
		public:
			void execute();

			MovementCommand(short a_xAxis, short a_yAxis) :
				xAxis(a_xAxis), yAxis(a_yAxis) 
				{}
			MovementCommand(short a_xAxis, short a_yAxis, 
				std::weak_ptr<eon::entity::Entity> a_srcEntity) :
				xAxis(a_xAxis), yAxis(a_yAxis) {
					srcEntity = a_srcEntity;
			}
			~MovementCommand() {}
			MovementCommand(const MovementCommand& a_other) {}

		protected:
			short xAxis = 0,
				  yAxis = 0;
		};
    }
}