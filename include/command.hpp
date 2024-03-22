#pragma once

#include "enums.hpp"

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
	};
}