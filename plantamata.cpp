#include <stdio.h>
#include "include/raylib.h"
#include "src/character.cpp"



int main(void)
{
    // Initialization

    const int screenWidth = 800;
    const int screenHeight = 450;


    InitWindow(screenWidth, screenHeight, "Plantamata");
    SetTargetFPS(60); 

    // Main game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
       
    
            DrawFPS(10, 10);

        
          
        EndDrawing();
      
    }

    CloseWindow(); 
    return 0;
}
