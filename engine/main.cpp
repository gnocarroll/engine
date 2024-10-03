#include <iostream>

#include "engine/Math/Vec.hpp"
#include "engine/Math/Mat.hpp"
#include "engine/OS/PrintError.hpp"
#include "engine/OS/Window.hpp"

int main() {
	OS::Window window("Test Fullscreen");

	if (!window.IsValid()) {
		OS::PrintError();
		return 1;
	}

	return 0;
}
