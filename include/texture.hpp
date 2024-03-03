#pragma once

#include <SDL2/SDL_surface.h>

#include <string>
#include <memory>

namespace eon {
    class Texture {
	public:
		virtual void load(std::string a_path) = 0;
		virtual void free() = 0;

		virtual ~Texture() {}

	protected:
		std::unique_ptr<SDL_Surface> surface; 
	};

	class PNGTexture : public Texture {
	public:
		void load(std::string a_path);
		void free() {
			if (surface)
				SDL_FreeSurface(surface.get());
		}

		PNGTexture(std::string a_path) 
			{ load(a_path); }
		~PNGTexture() 
			{ free(); }
		PNGTexture(const PNGTexture& a_other) {}
	};

	// TODO: JPEGXL implementation
	class JPEGXLTexture : public Texture {

	};
}