#include "engine/OS/Window.hpp"

#include <SDL2/SDL_video.h>

namespace OS {
	Window::Window(const std::string& _title, int w, int h) : title(_title),
		width(w), height(h), isFullscreen(false) {
		windowPtr = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, width, height, 0);
	}
	Window::Window(const std::string& _title) : title(_title),
		isFullscreen(true) {
		windowPtr = SDL_CreateWindow(title.c_str(), 0, 0, 0, 0,
			SDL_WINDOW_FULLSCREEN_DESKTOP);

		SDL_GetWindowSize(static_cast<SDL_Window*>(windowPtr),
			&width, &height);
	}

	Window::~Window() {
		SDL_DestroyWindow(static_cast<SDL_Window*>(windowPtr));
		windowPtr = nullptr;
	}
}