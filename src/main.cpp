// #define SDL_MAIN_HANDLED

#include <iostream>
// #include <imgui/imgui.h>
// #include <imgui/imgui_impl_sdl2.h>
// #include <imgui/imgui_impl_opengl3.h>
// #include <sdl/SDL.h>
// #include <sdl/SDL_opengl.h>
// #include <gl/GL.h>

#include <entity.hpp>

int main(int argc, char* argv[]) {
	std::cout << "Hello world!\n";
	Eon::Player e(0);
	e.DisplayID();
    return 0;
}