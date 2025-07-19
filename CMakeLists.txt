cmake_minimum_required(VERSION 3.24)
project(WaterSim)

# Workaround for CLang and RayLib's compound literals
# See: https://github.com/raysan5/raylib/issues/1343
set(CMAKE_CXX_STANDARD 11)

# ===== Dependencies =====
include(FetchContent)

include(cmake/raylib.cmake)
include(cmake/imgui.cmake)
include(cmake/rlimgui.cmake)

# ===== Our Project =====
set(SOURCE_FILES
	src/main.cpp
	src/Water.cpp
	src/UI.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} rlimgui)