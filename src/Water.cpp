#include "raylib.h"
#include "raymath.h"
#include "rlImGui.h"
#include "imgui.h"

#include "Water.hpp"

Water::Water(){

    //Defaults Values (ALL SUBJECT TO CHANGE)
    Gravity = 191.0f;
    Velocity = {0, 0};
    Position = {(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2};
    Dampening = 0.7f;
    Size = 8;
    Num_Bounces = 0;
    Bounce_Limit = 4;

}

void Water::Draw(){

    //Draws the particle
    DrawCircle(Position.x, Position.y, Size, PURPLE);

}

void Water::Update(){

    //If the Particle hits the bottom of the screen
    if(Position.y + Size > GetScreenHeight()){
    
        Position.y = Position.y - 8;
        Velocity.y *= Dampening * -1;
        Num_Bounces++;


    }

    else if(Num_Bounces != Bounce_Limit){

        //This absolute mess make sure that, no matter the frame rate, the game runs the same
        Velocity.y += Gravity * GetFrameTime() * 0.5f;
        Position.x += Velocity.x * GetFrameTime();
        Position.y += Velocity.y * GetFrameTime();
        Velocity.y += Gravity * GetFrameTime() * 0.5f;

    }


    if(Num_Bounces == Bounce_Limit){

        Velocity.y = 0;
        Position.y = GetScreenHeight() - Size;
            
    }


}

void Water::RenderUI(){

    ImGui::Begin("Water Values Debug");

    if(ImGui::Button("Reset Position", ImVec2(180, 24))){

        Position = {(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2};
        Velocity = {0, 0};
        Num_Bounces = 0;

    }

    ImGui::DragFloat("Size", &Size);    
    ImGui::DragFloat("Gravity", &Gravity);
    ImGui::DragFloat("Dampening", &Dampening);
    ImGui::DragFloat("Bounce Limit", &Bounce_Limit);

    ImGui::Text("X: %.2f", Position.x);
    ImGui::Text("Y: %.2f", Position.y);
    ImGui::Text("Velocity Y: %.2f", Velocity.y);
    ImGui::Text("Velocity X: %0.2f", Velocity.x);
    ImGui::End();

}