#include "raylib.h"
#include "imgui.h"
#include "rlImGui.h"

#include "Water.hpp"
#include "UI.hpp"

#include<vector>

int main(){

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 600, "Water Sim");
	rlImGuiSetup(true);
	SetTargetFPS(100);

	UI Ui = UI();

	std::vector<Water> waterParticles;
	Water water(Vector2{14, 0}, 8);
	water.Spawn(waterParticles, 8);

	while(WindowShouldClose() == false){

		BeginDrawing();
		ClearBackground(DARKGRAY);
		rlImGuiBegin();
		
		DrawFPS(3, 3);

		Ui.RenderUI(waterParticles);

		for(Water &water : waterParticles){

			water.Update(water);
			water.Draw(waterParticles);

		}

		rlImGuiEnd();
		EndDrawing();

	}

	rlImGuiShutdown();
	CloseWindow();

}