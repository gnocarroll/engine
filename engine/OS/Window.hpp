#pragma once

#include <string>
#include <utility>

namespace OS {
	class Window {
	private:
		void* windowPtr;
		const std::string title;
		int width;
		int height;
		bool isFullscreen;
	public:
		Window(const std::string& title, int w, int h);
		Window(const std::string& title);

		Window(const Window& other) = delete;
		Window(Window&& other) noexcept = default;

		~Window();

		bool IsValid() const {
			return (windowPtr != nullptr);
		}

		void* GetWindowPtr() const {
			return windowPtr;
		}

		const std::string& GetTitle() const {
			return title;
		}

		int GetWidth() const {
			return width;
		}
		int GetHeight() const {
			return height;
		}

		std::pair<int, int> GetDim() const {
			return std::make_pair(width, height);
		}

		bool IsFullscreen() const {
			return isFullscreen;
		}
	};
}