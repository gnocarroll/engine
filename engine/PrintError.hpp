#pragma once

#include <iostream>
#include <string>

#if __has_include(<SDL2/SDL_error.h>)

#include <SDL2/SDL_error.h>

inline void perrorSDL(const std::string& s) {
	std::cerr << s << ": " << SDL_GetError() << '\n';
}

#endif