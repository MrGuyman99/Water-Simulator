#include "raylib.h"
#include "raymath.h"
#include "rlImGui.h"
#include "imgui.h"

#include "Water.hpp"

#include<iostream>

Water::Water(Vector2 Position, float Size){

    //Defaults Values (ALL SUBJECT TO CHANGE)
    Gravity = 191.0f;
    Velocity = {0, 0};
    Dampening = 0.7f;
    Num_Bounces = 0;
    Bounce_Limit = 4;
    this->Size = Size;
    this->Position = Position;

}

void Water::Draw(std::vector<Water> &vector){

    //Draws the particle
    DrawCircle(Position.x, Position.y, Size, PURPLE);
    int PreviousX = 0;
    int PreviousY = 0;

    for(size_t i = 0; i < vector.size(); i++){

        if(i == 0){

            PreviousX = vector[i].Position.x;
            PreviousY = vector[i].Position.y;
            continue;

        }

        DrawLine(PreviousX, PreviousY, vector[i].Position.x, vector[i].Position.y, PURPLE);

        PreviousX = vector[i].Position.x;
        PreviousY = vector[i].Position.y;

    }

}

void Water::Update(Water &water){

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

    //Simple thing to draw
    DrawLine(Position.x, Position.y, water.Position.x, water.Position.y, PURPLE);

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
    ImGui::DragFloat("Position X", &Position.x);
    ImGui::DragFloat("Position Y", &Position.y);

    ImGui::Text("X: %.2f", Position.x);
    ImGui::Text("Y: %.2f", Position.y);
    ImGui::Text("Velocity Y: %.2f", Velocity.y);
    ImGui::Text("Velocity X: %0.2f", Velocity.x);
    ImGui::End();

}

void Water::Spawn(std::vector<Water> &vector, int num_spawn){

    for(int i = 0; num_spawn >= i; i++){

        vector.emplace_back(Vector2{(float)GetScreenWidth() / 2 + (i * 32), (float)GetScreenHeight() / 2}, 8);
        std::cout << vector[i].Position.x << std::endl << vector[i].Position.y << std::endl;

    }

}