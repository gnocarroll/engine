#include <cstdlib>
#include <iostream>

#include "engine/OS/Events.hpp"
#include "engine/OS/Window.hpp"
#include "engine/OS/Subsystem.hpp"
#include "engine/Render/Render2D.hpp"

int main() {
	std::ios_base::sync_with_stdio(false);

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

	while (!OS::ShouldQuit()) {
		OS::PollEvents();

		V2 points[2] = { V2(0.0f, 0.0f), V2(100.0f, 100.0f) };

		render2D.SetDrawColor(255, 255, 255, 255);
		render2D.Clear();
		render2D.SetDrawColor(255, 0, 0, 255);
		render2D.DrawLines(points, 2);
		render2D.ToOutput();
	}

	return 0;
}
