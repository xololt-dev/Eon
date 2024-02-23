#pragma once

#include "SDL_render.h"
#include "SDL_stdinc.h"
#include "SDL_video.h"
#include <string>
#include <utils.hpp>

#include <SDL2/SDL.h>

#include <memory>

namespace eon {
	namespace render {
		class Component : public eon::Component {
		public:
			virtual void update() = 0;

			Component() {
				type = ComponentType::Render;
			}
     		~Component() {}
     		Component(const Component &a_other) {}
		};

		template<typename _Tp, typename _Up>
		inline std::shared_ptr<_Tp>
		static_pointer_cast(const std::shared_ptr<eon::render::Component>& __r);

		class TextureComponent : public render::Component {
		public:
			void update();

			TextureComponent() {}
			TextureComponent(std::string a_path) {
				texture->load(a_path);
			}
			~TextureComponent() {}
			TextureComponent(const Component &a_other) {}

			void setTexture(std::string a_path) 
				{ texture->load(a_path); };

		protected:
			std::unique_ptr<Texture> texture;
		};

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
			}
			Manager(std::string a_title, int a_width, int a_height, SDL_WindowFlags a_flags = SDL_WindowFlags(0)) {
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
			}
			~Manager() {
				SDL_GL_DeleteContext(glContext);
				SDL_DestroyRenderer(renderer);
				renderer = nullptr;
    			SDL_DestroyWindow(window);
				window = nullptr;
				SDL_Quit();
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