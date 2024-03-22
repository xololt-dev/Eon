#pragma once

#include "command.hpp"
#include "enums.hpp"
#include "render/render_manager.hpp"

#include <SDL2/SDL_stdinc.h>

namespace eon {
//	namespace render {
//	    class Manager;
//	}

	namespace render {
        class RenderDrawColorCommand : public eon::Command {
		public:
			void execute();

			RenderDrawColorCommand(Uint8 a_red, Uint8 a_green, Uint8 a_blue, Uint8 a_alpha) :
				red(a_red), green(a_green), blue(a_blue), alpha(a_alpha) {
					type = CommandType::RenderDrawColorCommand;
			}
			~RenderDrawColorCommand() {}
			RenderDrawColorCommand(const RenderDrawColorCommand& a_other) {}

			void setManager(eon::render::Manager& a_manager) 
				{ manager = &a_manager; };

		protected:
			Uint8 red;
			Uint8 green;
			Uint8 blue;
			Uint8 alpha;
			eon::render::Manager* manager;
		};
    }
}