#include "UI.hpp"
#include "imgui.h"
#include "Water.hpp"

void UI::RenderUI(std::vector<Water> &vector){

    ImGui::Begin("Water Values debug");

    if(ImGui::Button("Reset Position", ImVec2(180, 24))){

        for(size_t i = 0; i < vector.size(); i++){

            vector[i].Position = {(float)GetScreenWidth() / 2 + (i * 32), (float)GetScreenHeight() / 2};
            vector[i].Velocity = {0, 0};
            vector[i].Num_Bounces = 0;

        }

    }

    for(size_t i = 0; i < vector.size(); i++){

        ImGui::PushID(i);
        ImGui::DragFloat("Size", &vector[i].Size);
        ImGui::PopID();

    }

    ImGui::End();

}
