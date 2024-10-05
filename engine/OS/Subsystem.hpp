#pragma once

#include "engine/MyIntDef.hpp"

namespace OS {
	namespace Subsys {
		enum Types : ui32 {
			Video = 0b1,
			Audio = 0b10,
			Controller = 0b100,
			Timer = 0b1000
		};

		int Init(ui32 flags);
		void CleanupAll();
	}
}