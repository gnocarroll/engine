#include "engine/Render/Render2D.hpp"

#include <iostream>

#include <SDL2/SDL_render.h>

#include "engine/Util.hpp"
#include "engine/OS/Window.hpp"
#include "engine/PrintError.hpp"

#define RCAST(p) (static_cast<SDL_Renderer*>(p))
#define POINT2DCAST(p) (reinterpret_cast<SDL_FPoint*>(p))

namespace Render {
	Render2D::Render2D(const OS::Window& _window) : window(_window),
		outWidth(0), outHeight(0) {
		renderPtr = SDL_CreateRenderer(
			static_cast<SDL_Window*>(window.GetWindowPtr()),
			-1, // => use first rendering driver supporting requested flags
			SDL_RENDERER_ACCELERATED);

		if (renderPtr) {
			UpdateDim();
		}
		else {
			perrorSDL(__func__);
		}
	}

	Render2D::~Render2D() {
		SDL_DestroyRenderer(RCAST(renderPtr));
	}

	int Render2D::UpdateDim() {
		int w = 0;
		int h = 0;

		if (SDL_GetRendererOutputSize(
			RCAST(renderPtr), &w, &h) < 0) {
			
			perrorSDL(__func__);
			return -1;
		}

		outWidth = static_cast<i32>(w);
		outHeight = static_cast<i32>(h);

		return 0;
	}

	int Render2D::Clear() {
		return Util::SDLWrapper<SDL_RenderClear>(RCAST(renderPtr));
	}
	void Render2D::ToOutput() {
		SDL_RenderPresent(RCAST(renderPtr));
	}

	int Render2D::SetDrawColor(ui8 r, ui8 g, ui8 b, ui8 a) {
		return Util::SDLWrapper<SDL_SetRenderDrawColor>(RCAST(renderPtr), r, g, b, a);
	}

	int Render2D::DrawLines(V2* points, int count) {
		return Util::SDLWrapper<SDL_RenderDrawLinesF>(RCAST(renderPtr), POINT2DCAST(points), count);
	}
}