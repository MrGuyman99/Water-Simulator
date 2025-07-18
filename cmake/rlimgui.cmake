# Fetches the version of rlimgui that we want

# rlimgui has no tags/branches, so choosing the current commit instead. 
# To update to a newer commit:
# - Visit https://github.com/raylib-extras/rlImGui/
# - Navigate to the commit you want
# - Click the button to "Copy full SHA..."
#
# Alternatively,  in a terminal:
# - git clone https://github.com/raylib-extras/rlImGui.git
# - git rev-parse HEAD
# - This will print the full SHA of the latest commit
#
# NOTE: NOT using GIT_REPOSITORY, because GitHub insists on asking for credentials even with a public repository
set(rlimui_COMMIT_FULL_SHA "c87062ac11a1ed1145f075f022470ae77a03c734")
set(rlimgui_URL "https://github.com/raylib-extras/rlImGui/archive/${rlimui_COMMIT_FULL_SHA}.tar.gz")
FetchContent_Declare(
    rlimgui
    URL ${rlimgui_URL}
)
FetchContent_MakeAvailable(rlimgui)
add_library(rlimgui STATIC ${rlimgui_SOURCE_DIR}/rlImGui.cpp)
target_link_libraries(rlimgui raylib imgui) # Needs access to Raylib
target_include_directories(rlimgui INTERFACE ${rlimgui_SOURCE_DIR})