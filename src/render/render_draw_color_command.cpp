#include "render/render_draw_color_command.hpp"
#include "render/render_manager.hpp"

void eon::render::RenderDrawColorCommand::execute() {
    manager->setRenderDrawColor(red, green, blue, alpha);
}