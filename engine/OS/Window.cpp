#include "engine/OS/Window.hpp"

#include <SDL2/SDL_video.h>

#include "engine/PrintError.hpp"

namespace OS {
	Window::Window(const std::string& _title, int w, int h) : title(_title),
		width(w), height(h), isFullscreen(false) {
		windowPtr = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, width, height, 0);

		if (!windowPtr) {
			perrorSDL(__func__);
		}
	}
	Window::Window(const std::string& _title) : title(_title),
		width(0), height(0), isFullscreen(true) {
		windowPtr = SDL_CreateWindow(title.c_str(), 0, 0, 0, 0,
			SDL_WINDOW_FULLSCREEN_DESKTOP);

		if (windowPtr) {
			SDL_GetWindowSize(static_cast<SDL_Window*>(windowPtr),
				&width, &height);
		}
		else {
			perrorSDL(__func__);
		}
	}

	Window::~Window() {
		SDL_DestroyWindow(static_cast<SDL_Window*>(windowPtr));
		windowPtr = nullptr;
	}
}