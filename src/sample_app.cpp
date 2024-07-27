#include "imgui_app.h"

int main(int argc, char* argv[]) {
	if (!ImGuiApp::init("Sample Imgui Application", 1024, 768)) {
		return -1;
	}

	while (ImGuiApp::loop()) {
		ImGui::Begin("Hello, world!");
		ImGui::Text("This is some useful text.");
		if (ImGui::Button("exit")) {
			ImGuiApp::request_quit();
		}
		ImGui::End();
	}

	ImGuiApp::shutdown();
}
