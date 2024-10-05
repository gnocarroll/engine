#include "engine/OS/Events.hpp"

#include <cstring>

#include <SDL2/SDL_Events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>

#include "engine/MyIntDef.hpp"
#include "engine/PrintError.hpp"

#define N_INPUTS (256)

// quitStatus -1 => should quit application
static int quitStatus = 0;
static inline int HandleEvent(const SDL_Event& event);

struct InputInfo {
	static i32 mouseX;
	static i32 mouseY;

	static i32 mouseOffsetX;
	static i32 mouseOffsetY;

	static bool inputFrame[N_INPUTS];
	static bool inputCurrent[N_INPUTS];

	static void Clear() {
		mouseOffsetX = 0;
		mouseOffsetY = 0;

		std::memset(inputFrame, 0, sizeof(inputFrame));
	}
};

namespace OS {
	int PollEvents() {
		// Each frame, some of the stored input info should be wiped so that
		// it can be replaced with the relevant info for the new frame
		InputInfo::Clear();

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

template<>
static inline int EventHandler<SDL_MOUSEMOTION>(const SDL_Event& event) {
	auto mouseEvent = ConvertEventTo<SDL_MouseMotionEvent>(event);

	InputInfo::mouseX = mouseEvent.x;
	InputInfo::mouseY = mouseEvent.y;
	InputInfo::mouseOffsetX += mouseEvent.xrel;
	InputInfo::mouseOffsetY += mouseEvent.yrel;
}

static inline int GetInputIdx(SDL_Keycode sym) {
	if (sym < 256) {
		return sym;
	}

	// TODO: Ability to record/query other inputs

	return -1;
}

/*
 *	Since there are separate enum values for SDL_KEYUP and SDL_KEYDOWN, this
 *  will be used for both.
 */
static inline int _EventHandlerKey(const SDL_Event& event) {
	auto keyEvent = ConvertEventTo<SDL_KeyboardEvent>(event);

	// toss out repeats, will do our own handling
	if (keyEvent.repeat) {
		return -1;
	}

	bool keyPressed = (keyEvent.state == SDL_PRESSED);
	SDL_Keycode sym = keyEvent.keysym.sym;

	int inputIdx = GetInputIdx(sym);

	if (inputIdx == -1) {
		return -1;
	}

	InputInfo::inputCurrent[inputIdx] = keyPressed;

	if (keyPressed) {
		InputInfo::inputFrame[inputIdx] = keyPressed;
	}

	return 0;
}

template<>
static inline int EventHandler<SDL_KEYUP>(const SDL_Event& event) {
	return _EventHandlerKey(event);
}

template<>
static inline int EventHandler<SDL_KEYDOWN>(const SDL_Event& event) {
	return _EventHandlerKey(event);
}

static inline int HandleEvent(const SDL_Event& event) {
	switch (event.type) {
		HANDLE_CASE(SDL_QUIT);
		HANDLE_CASE(SDL_WINDOWEVENT);
		HANDLE_CASE(SDL_KEYDOWN);
		HANDLE_CASE(SDL_KEYUP);
	}
}