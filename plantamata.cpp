#include <stdio.h>
#include <iostream>
#include "include/raylib.h"
#include "src/Character.cpp"



int main(void)
{
    // Initialization

    std::cout << "awewewe" << std::endl;

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Plantamata");
    SetTargetFPS(60); 

    std::cout << "Creating player..." << std::endl;
    Character player(screenWidth/2, screenHeight/2);
    std::cout << "Player initialized" << std::endl;

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update

        player.MoveLeft();
        if (IsKeyDown(KEY_RIGHT) == true) {player.MoveRight();}
        if (IsKeyDown(KEY_UP) == true) {player.MoveUp();}
        if (IsKeyDown(KEY_DOWN) == true) {player.MoveDown();}
        player.Update();

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);
       
        
        player.Draw();
        
        DrawFPS(10, 10);
          
        EndDrawing();
      
    }

    CloseWindow(); 
    return 0;
}
