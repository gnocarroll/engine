#pragma once

#include "engine/PrintError.hpp"

namespace Util {
	template<auto SDLFunc, typename... Args>
	static inline int SDLWrapper(Args... args) {
		if (SDLFunc(args...) == 0) {
			return 0;
		}

		perrorSDL(__func__);
		return -1;
	}
}