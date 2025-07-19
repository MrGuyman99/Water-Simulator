#pragma once
#include "raylib.h"
#include<vector>

class Water{

    public:

        Water(Vector2 Position);
        void Draw(std::vector<Water> &vector);
        void Update(Water &water);
        void RenderUI();
        void Spawn(std::vector<Water> &vector, int num_spawn);

    private:

        //Super Simple Stuff
        Vector2 Position;
        Vector2 Velocity;
        float Gravity;
        float Dampening;
        float Size;
        int Num_Bounces;
        float Bounce_Limit;

};  