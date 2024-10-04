#pragma once

#include <string>

#include "engine/Math/Vec.hpp"
#include "engine/MyIntDef.hpp"

namespace OS {
	class Window {
	private:
		void* windowPtr;
		const std::string title;
		i32 width;
		i32 height;
		bool isFullscreen;
	public:
		Window(const std::string& title, i32 w, i32 h);
		Window(const std::string& title);

		Window(const Window& other) = delete;
		Window(Window&& other) noexcept = default;

		~Window();

		void UpdateDim();

		bool IsValid() const {
			return (windowPtr != nullptr);
		}

		void* GetWindowPtr() const {
			return windowPtr;
		}

		const std::string& GetTitle() const {
			return title;
		}

		i32 GetWidth() const {
			return width;
		}
		i32 GetHeight() const {
			return height;
		}

		V2i GetDim() const {
			return V2i(width, height);
		}

		bool IsFullscreen() const {
			return isFullscreen;
		}
	};
}