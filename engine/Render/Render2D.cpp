#include "engine/Render/Render2D.hpp"

#include <iostream>

#include <SDL2/SDL_render.h>

#include "engine/OS/Window.hpp"
#include "engine/PrintError.hpp"

namespace Render {
	Render2D::Render2D(const OS::Window& _window) : window(_window) {
		renderPtr = SDL_CreateRenderer(
			static_cast<SDL_Window*>(window.GetWindowPtr()),
			-1, // => use first rendering driver supporting requested flags
			SDL_RENDERER_ACCELERATED);

		if (!renderPtr) {
			perrorSDL(__func__);
		}
	}

	Render2D::~Render2D() {
		SDL_DestroyRenderer(static_cast<SDL_Renderer*>(renderPtr));
	}
}