## IMGUI_APP

Packaging Dear::imgui and SDL 2, into a complete staticly linked library to build multi platform GUI apps, with no external dependencies. 
Uses SDL renderer to render output so is not dependent on OpenGL, Vulkan, or Direct3d. (although SDL itself may use these)

## Usage: 

Use `FetchContent` to include lib in your project:
 
```cmake
include(FetchContent)
FetchContent_Declare(
	imgui_app
    GIT_REPOSITORY "https://github.com/0xcafed00d/imgui_app.git"
    GIT_TAG main
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(imgui_app)
```

Build your application as usual with CMAKE;
```cmake
add_executable(my_app src/main.cpp)

# set location of SDL
target_link_directories(my_app
	PRIVATE
	${SDL2_LIB_DIR}
)

# link to SDL and imgui_app + add any other libs you need
target_link_libraries(my_app 
  PRIVATE
  SDL2::SDL2main
  SDL2::SDL2-static
  imgui_app)
```

You can overide the location and version of SDL2 that is fetched by setting the variables `SDL2_URL` and `SDL2_TAG` in your CMakeLists.txt before you call FetchContent: 
```cmake
set(SDL2_URL "https://github.com/libsdl-org/SDL.git")
set(SDL2_TAG "release-2.30.5")
```

There are only 4 api functions, init, loop, request_quit, and shutdown:
 
```cpp
#include "imgui_app.h"

int main(int argc, char* argv[]) {
	ImGuiApp::init("Window Title", 640, 480);

	while (ImGuiApp::loop()) {
		ImGui::Begin("Hello, world!");
		ImGui::Text("This is some useful text.");
		if (ImGui::Button("Quit")) {
			ImGuiApp::request_quit();
		}
		ImGui::End();
	}

	ImGuiApp::shutdown();
}

```
