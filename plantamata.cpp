#include <stdio.h>
#include <iostream>
#include "include/raylib.h"
#include "src/Character.cpp"
#include "src/worldgen/worldgen.cpp"

int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Plantamata");
    SetTargetFPS(60); 

    std::cout << "Creating player..." << std::endl;
    worldGen();
    std::cout << "Player initialized" << std::endl;

    std::cout << "Creating player..." << std::endl;
    Character player(screenWidth/2, screenHeight/2);
    std::cout << "Player initialized" << std::endl;

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        float deltaTime = GetFrameTime();
        player.Update(deltaTime);

        // Draw
        BeginDrawing();
        
        ClearBackground(GRAY);
        drawWorld();
        player.Draw();

        DrawFPS(10, 10);
        
        EndDrawing();
    }

    CloseWindow(); 
    return 0;
}