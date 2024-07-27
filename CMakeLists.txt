cmake_minimum_required(VERSION 3.16)

project(imgui_app)

include (cmake/tools.cmake)

if ("${SDL2_URL}" STREQUAL "")
	set(SDL2_URL "https://github.com/libsdl-org/SDL.git")
endif()

if ("${SDL2_TAG}" STREQUAL "")
	set(SDL2_TAG "release-2.30.5")
endif()


add_library(imgui_app
	STATIC
	src/imgui_app.h
	src/imgui_app.cpp
	src/imgui/imconfig.h
	src/imgui/imgui.cpp
	src/imgui/imgui_demo.cpp
	src/imgui/imgui_draw.cpp
	src/imgui/imgui_internal.h
	src/imgui/imgui_tables.cpp
	src/imgui/imgui_widgets.cpp
	src/imgui/imstb_rectpack.h
	src/imgui/imstb_textedit.h
	src/imgui/imstb_truetype.h
	src/imgui/backends/imgui_impl_sdl2.cpp
	src/imgui/backends/imgui_impl_sdl2.h
	src/imgui/backends/imgui_impl_sdlrenderer2.cpp
	src/imgui/backends/imgui_impl_sdlrenderer2.h
)

include(FetchContent)
set(SDL_SHARED FALSE CACHE BOOL "Build a SDL shared library (if available)")
set(SDL_STATIC TRUE CACHE BOOL "Build a SDL static library (if available)")

FetchContent_Declare(
    SDL2
    GIT_REPOSITORY ${SDL2_URL}
    GIT_TAG ${SDL2_TAG}
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
	OVERRIDE_FIND_PACKAGE
)
FetchContent_MakeAvailable(SDL2)

set (SDL2_INCLUDE_DIR ${SDL2_SOURCE_DIR}/include)
set (SDL2_LIB_DIR ${SDL2_BINARY_DIR})


target_include_directories(imgui_app 
	PUBLIC
	src 
	src/imgui 
	src/imgui/backends
	${SDL2_INCLUDE_DIR}
)

target_link_libraries(imgui_app 
	SDL2::SDL2main
	SDL2::SDL2-static
)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
	# Only build the example if this is the main project

	add_executable(imgui_app_example
		src/sample_app.cpp
	)

	target_link_libraries(imgui_app_example 
		imgui_app
		SDL2::SDL2main
		SDL2::SDL2-static
	)

endif()