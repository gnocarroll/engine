#include "engine/OS/Subsystem.hpp"

#include <SDL2/SDL.h>

#include "engine/PrintError.hpp"

namespace OS {
	namespace Subsys {
		static inline ui32 GetRealFlag(ui32 flag) {
			switch (flag) {
			case Video:
				return SDL_INIT_VIDEO;
			case Audio:
				return SDL_INIT_AUDIO;
			case Controller:
				return SDL_INIT_GAMECONTROLLER;
			case Timer:
				return SDL_INIT_TIMER;
			default:
				break;
			}

			return 0;
		}

		int Init(ui32 flags) {
			ui32 realFlags = 0;

			// for each flag get "real flag" i.e. flag that will be used by
			// what this wraps around
			for (ui32 i = 0, currentFlag = 0b1; i < 32;
				i++, currentFlag << 1) {

				realFlags |= GetRealFlag(flags & currentFlag);
			}

			int ret = SDL_Init(realFlags);

			if (ret < 0) {
				perrorSDL(__func__);
			}

			return ret;
		}

		void CleanupAll() {
			SDL_Quit();
		}
	}
}