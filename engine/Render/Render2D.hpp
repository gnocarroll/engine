#pragma once

#include "engine/Math/Vec.hpp"
#include "engine/MyIntDef.hpp"
#include "engine/OS/Window.hpp"

namespace Render {
	class Render2D {
	private:
		const OS::Window& window;
		void* renderPtr;

		i32 outWidth;
		i32 outHeight;
	public:
		// The renderer will render things to the provided window
		Render2D(const OS::Window& _window);
		Render2D(const Render2D& other) = delete;
		Render2D(Render2D&& other) = default;

		~Render2D();

		int Clear();
		void ToOutput();

		int UpdateDim();

		int SetDrawColor(ui8 r, ui8 g, ui8 b, ui8 a);
		int DrawLines(V2* points, int count);

		bool IsValid() const {
			return (renderPtr != nullptr);
		}

		i32 GetWidth() const {
			return outWidth;
		}
		i32 GetHeight() const {
			return outHeight;
		}

		V2i GetDim() const {
			return V2i(outWidth, outHeight);
		}
	};
}