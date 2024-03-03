#pragma once

#include "component.hpp"
#include "enums.hpp"

#include <memory>

namespace eon {
    namespace entity {
        class Entity;
    }

    class Command {
	public:
		virtual void execute() = 0;
		// virtual void undo() {};

		virtual ~Command() {}

		CommandType getType()
			{ return type; };

	protected:
		CommandType type;
		std::weak_ptr<eon::entity::Entity> srcEntity;
	};
}