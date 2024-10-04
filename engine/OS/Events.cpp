#include "engine/OS/Events.hpp"

#include <SDL2/SDL_Events.h>

#include "engine/MyIntDef.hpp"
#include "engine/PrintError.hpp"

// quitStatus -1 => should quit application
static int quitStatus = 0;
static inline int HandleEvent(const SDL_Event& event);

namespace OS {
	int PollEvents() {
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			HandleEvent(event);
		}

		return quitStatus;
	}

	bool ShouldQuit() {
		return quitStatus == -1;
	}
}

#define HANDLE_CASE(t) case t: return EventHandler<t>(event)

template <typename T>
inline const T& ConvertEventTo(const SDL_Event& event) {
	return *reinterpret_cast<const T*>(&event);
}

template <ui32 eventType>
static inline int EventHandler(const SDL_Event& event) {
	perrorMsg(__func__, "event handler not implemented");
	return 0;
}

template <>
static inline int EventHandler<SDL_QUIT>(const SDL_Event& event) {
	quitStatus = -1;
	return -1;
}

template <>
static inline int EventHandler<SDL_WINDOWEVENT>(const SDL_Event& event) {
	const SDL_WindowEvent& windowEvent =
		ConvertEventTo<SDL_WindowEvent>(event);

	switch (windowEvent.event) {
	case SDL_WINDOWEVENT_CLOSE:
		quitStatus = -1;
		return -1;
	}
}

static inline int HandleEvent(const SDL_Event& event) {
	switch (event.type) {
		HANDLE_CASE(SDL_QUIT);
		HANDLE_CASE(SDL_WINDOWEVENT);
	}
}