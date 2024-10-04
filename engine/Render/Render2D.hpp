#include "engine/OS/Window.hpp"

namespace Render {
	class Render2D {
	private:
		const OS::Window& window;
		void* renderPtr;

		int outWidth;
		int outHeight;

	public:
		// The renderer will render things to the provided window
		Render2D(const OS::Window& _window);
		Render2D(const Render2D& other) = delete;
		Render2D(Render2D&& other) = default;

		~Render2D();

		bool IsValid() {
			return (renderPtr != nullptr);
		}
	};
}