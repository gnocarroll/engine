#include <cstdlib>
#include <iostream>

#include "engine/OS/Window.hpp"
#include "engine/OS/Subsystem.hpp"
#include "engine/Render/Render2D.hpp"

int main() {
	std::ios_base::sync_with_stdio(false);

	V3 example(0.0f, 1.0f, 2.0f);

	std::cout << example << '\n';

	// Setup subsystems
	if (OS::Subsys::Init(OS::Subsys::Video) < 0) {
		return 1;
	}

	// Cleanup all subsystems at program exit
	atexit(OS::Subsys::CleanupAll);

	OS::Window window("Test Window", 800, 600);

	if (!window.IsValid()) {
		return 1;
	}

	Render::Render2D render2D(window);

	if (!render2D.IsValid()) {
		return 1;
	}

	return 0;
}
