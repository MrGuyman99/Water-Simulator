#pragma once
#include "raylib.h"

class Water{

    public:

        Water();
        void Draw();
        void Update();
        void RenderUI();

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