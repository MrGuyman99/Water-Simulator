# Fetches the version of raylib that we need

# Special linking needed for Raylib with Emscripten
# IMPORTANT: Do this *before* importing RayLib
if(EMSCRIPTEN)
    set(PLATFORM Web CACHE INTERNAL "")
    list(APPEND CMAKE_EXE_LINKER_FLAGS "-s USE_GLFW=3 -sASYNCIFY")
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
endif()

set(RAYLIB_VERSION 5.5)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    FIND_PACKAGE_ARGS ${RAYLIB_VERSION} EXACT
)
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)