#pragma once
#include "raylib.h"
#include<vector>

class Water{

    //Everything is made public so it can be passed to UI.cpp (It's the most expandable way of doing things)
    public:

        Water(Vector2 Position, float Size);
        void Draw(std::vector<Water> &vector);
        void Update(Water &water);
        void RenderUI();
        void Spawn(std::vector<Water> &vector, int num_spawn);
        float Size;

        //Super Simple Stuff
        Vector2 Position;
        Vector2 Velocity;
        float Gravity;
        float Dampening;
        int Num_Bounces;
        float Bounce_Limit;

};  