#include "imgui/imgui.h"

class SDL_Window;
class SDL_Renderer;

namespace ImGuiApp {
	bool init(const char* title, int width, int height);
	void request_quit();
	bool loop();
	void shutdown();

	void get_SDL_window_and_renderer(SDL_Window** window, SDL_Renderer** renderer);

}  // namespace ImGuiApp
