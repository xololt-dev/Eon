#pragma once

#include "render_component.hpp"
#include "render/render_manager.hpp"
#include "texture.hpp"

#include <memory>

namespace eon {
	namespace render {
		class TextureComponent : public render::Component {
		public:
			void update();

			TextureComponent(render::Manager* a_manager) {
				manager = a_manager;
			}
			TextureComponent(render::Manager* a_manager, std::string a_path) {
				manager = a_manager;
				texture->load(a_path);
			}
			~TextureComponent() {}
			TextureComponent(const TextureComponent& a_other) {}

			void setTexture(std::string a_path) 
				{ texture->load(a_path); }

		protected:
			std::unique_ptr<Texture> texture;
		};
	}
}
