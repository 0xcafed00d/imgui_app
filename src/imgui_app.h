#include "imgui/imgui.h"

namespace ImGuiApp {
	bool init(const char* title, int width, int height);
	void request_quit();
	bool loop();
	void shutdown();
}  // namespace ImGuiApp
