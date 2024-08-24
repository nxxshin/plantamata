#include <iostream>
#include "raylib.h"

const int GRID_SIZE = 64;
const int SIZE = 32;
Texture2D tileset;

struct Cell {
    float x;
    float y;
    float sourceX;
    float sourceY;
};

float sourceX = 16*11;
float sourceY = 16*3;


Cell grid[GRID_SIZE][GRID_SIZE];

void loadTileset() {
tileset = LoadTexture("resources/world/tilesheet.png");
};

void assignTile(float &sourceX, float &sourceY) {

    float randNumber = rand() % 25;
    struct Grass {
        int x = 16*11;
        int y = 3*16;
    };

    Grass grass;

    int flower1 = 16*10;
    int flower2 = 16*12;


    sourceX = (randNumber == 1) ? grass.x : grass.x;
    sourceY = (randNumber == 1) ? grass.y : grass.y;
    sourceX = (randNumber == 2) ? flower1 : sourceX;
    sourceY = (randNumber == 2) ? 0 : sourceY;
    sourceX = (randNumber == 0) ? flower2 : sourceX;
    sourceY = (randNumber == 0) ? 0 : sourceY;
    sourceX = (randNumber == 3) ? grass.x + 32 : sourceX;
    sourceY = (randNumber == 3) ? grass.y: sourceY;
    sourceX = (randNumber == 4) ? grass.x + 48 : sourceX;
    sourceY = (randNumber == 4) ? grass.y: sourceY;

}

void createGrid(int GRID_SIZE) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
        float x = i * 32;
        float y = j * 32;
        grid[i][j].x = x;
        grid[i][j].y = y;
        assignTile(sourceX, sourceY);
        grid[i][j].sourceX = sourceX;
        grid[i][j].sourceY = sourceY;

       
        
    }
}
}



void drawWorld() {


    float size = 32;
    Color color = {160, 205, 62, 126};

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
           float x =  grid[i][j].x;
           float y = grid[i][j].y;
    Vector2 position = {x,y};
    DrawRectangle(x,y, size, size, color); 
 

    Rectangle drawSource = {grid[i][j].sourceX, grid[i][j].sourceY, 16, 16};
    Rectangle drawDest = {x, y, 32, 32};

    // assignTile(sourceX, sourceY);

    DrawTexturePro(tileset, drawSource, drawDest, {0, 0}, 0, WHITE);
    
    // DrawRectangleLines(x, y, size, size, BLUE);

    }}
}



void worldGen() {
    createGrid(GRID_SIZE);
   
    loadTileset();
}
