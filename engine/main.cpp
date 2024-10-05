#include <cstdlib>
#include <iostream>

#include "engine/OS/Events.hpp"
#include "engine/OS/Window.hpp"
#include "engine/OS/Subsystem.hpp"
#include "engine/Render/Render2D.hpp"
#include "engine/Time/DeltaT.hpp"

int main() {
	std::ios_base::sync_with_stdio(false);

	// Setup subsystems
	if (OS::Subsys::Init(OS::Subsys::Video | OS::Subsys::Audio) < 0) {
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

	Time::StartTimer();

	while (OS::PollEvents() != -1) {
		float deltaT = Time::UpdateDeltaT();
	}

	return 0;
}
