#include "engine/Time/DeltaT.hpp"

#include <SDL2/SDL_timer.h>

#include "engine/MyIntDef.hpp"

static ui64 oldTime = 0;
static float deltaT = 0.0f;

namespace Time {
	float UpdateDeltaT() {
		ui64 newTime = SDL_GetTicks64();

		// units are milliseconds for SDL_GetTicks64
		deltaT = static_cast<float>(newTime - oldTime) / 1000.0f;
		oldTime = newTime;

		return deltaT;
	}

	float GetDeltaT() {
		return deltaT;
	}

	float StartTimer() {
		oldTime = SDL_GetTicks64();
	}
}