#pragma once

namespace OS {
	// Returns -1 if should quit application, 0 otherwise
	int PollEvents();

	bool ShouldQuit();
}