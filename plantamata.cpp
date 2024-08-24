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

    Camera2D camera = { 0 };
    camera.offset = { screenWidth/2 - player.frameWidth, screenHeight/2 - player.frameWidth };
    camera.target = player.position;
    camera.rotation = 0;
    camera.zoom = 1;

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        float deltaTime = GetFrameTime();
        player.Update(deltaTime);

        // Draw
        BeginDrawing();
        BeginMode2D(camera); 


        
        ClearBackground(Color {240, 240, 240, 226});
        drawWorld();
        player.Draw();
        camera.target = player.position;

        DrawFPS(10, 10);
        EndMode2D();
        EndDrawing();
        
    }

    CloseWindow(); 
    return 0;
}