#include "raylib.h"
#include "imgui.h"
#include "rlImGui.h"

#include "Water.hpp"

int main(){

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 600, "Water Sim");
	rlImGuiSetup(true);
	
	SetTargetFPS(100);

	Water water = Water();

	while(WindowShouldClose() == false){

		BeginDrawing();
		ClearBackground(DARKGRAY);
		
		DrawFPS(3, 3);
		water.Draw();
		
		rlImGuiBegin();
		water.RenderUI();
		rlImGuiEnd();
		
		EndDrawing();
		water.Update();

	}

	rlImGuiShutdown();
	CloseWindow();

}