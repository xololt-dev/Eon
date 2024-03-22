#pragma once

#include <SDL2/SDL.h>

#include "component.hpp"
#include "manager.hpp"

#include <memory>
#include <string>
#include <iostream>

namespace eon {
    namespace render {
        class Manager : public eon::Manager {
		public:
			void update();
			std::shared_ptr<eon::Component> createComponent(ComponentType a_type);
			void deleteComponent(std::shared_ptr<eon::Component> a_comp);

			Manager() {
				SDL_WindowFlags window_flags = (SDL_WindowFlags)
					(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
				window = SDL_CreateWindow("Dear ImGui SDL2+OpenGL3 example",
					SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
					1280, 720, 
					window_flags);
				
				if (window == nullptr)
					printf("Error: SDL_CreateWindow(): %s\n", SDL_GetError());

				glContext = SDL_GL_CreateContext(window);
    			SDL_GL_MakeCurrent(window, glContext);

				renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
				
				if (renderer == nullptr)
					printf("Error: SDL_CreateRenderer(): %s\n", SDL_GetError());

				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

				std::cout << "[INFO] Created RenderManager\n";
			}
			Manager(SystemsManager& a_sysManager, std::string a_title, int a_width, int a_height, SDL_WindowFlags a_flags = SDL_WindowFlags(0)) {
				window = SDL_CreateWindow(a_title.c_str(),
					SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
					a_width, a_height, 
					a_flags);
				
				if (window == nullptr)
					printf("Error: SDL_CreateWindow(): %s\n", SDL_GetError());

				glContext = SDL_GL_CreateContext(window);
    			SDL_GL_MakeCurrent(window, glContext);

				renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
				
				if (renderer == nullptr)
					printf("Error: SDL_CreateRenderer(): %s\n", SDL_GetError());

				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

				std::cout << "[INFO] Created RenderManager\n";
				setSystemsManager(&a_sysManager);
			}
			~Manager() {
				SDL_GL_DeleteContext(glContext);
				SDL_DestroyRenderer(renderer);
				renderer = nullptr;
    			SDL_DestroyWindow(window);
				window = nullptr;
				SDL_Quit();
				systemsManager = nullptr;
			}
			Manager(const Manager& a_other) {}

			void setRenderDrawColor(Uint8 a_red, Uint8 a_green, Uint8 a_blue, Uint8 a_alpha) {
				SDL_SetRenderDrawColor(renderer, a_red, a_green, a_blue, a_alpha);
			}
		
		protected:
			SDL_Window* window;
			SDL_Renderer* renderer;
			SDL_GLContext glContext;
		};
    }
}