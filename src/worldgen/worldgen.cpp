#include <iostream>
#include "raylib.h"

const int GRID_SIZE = 32;
const int SIZE = 32;
Texture2D tileset;

struct Cell {
    float x;
    float y;
    int tileNumber;
};

float sourceX;
float sourceY;


Cell grid[GRID_SIZE][GRID_SIZE];

void loadTileset() {
tileset = LoadTexture("resources/world/tilesheet.png");
};

void createGrid(int GRID_SIZE) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
        float x = i * 32;
        float y = j * 32;
        grid[i][j].x = x;
        grid[i][j].y = y;
        
    }
}
}

void assignTile(float &sourceX, float &sourceY) {
    float randNumber = rand() % 25;
    sourceY = 0;
    sourceX = (randNumber == 1) ? 0 : 0;
    sourceX = (randNumber == 2) ? 48 : sourceX;
    sourceX = (randNumber == 0) ? 16*14 : sourceX;
    sourceY = (randNumber == 0) ? 16: sourceY;

}

void drawWorld() {


    float size = 32;
    Color color = LIGHTGRAY;

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
           float x =  grid[i][j].x;
           float y = grid[i][j].y;
    Vector2 position = {x,y};
    // DrawRectangle(x,y, size, size, color); 
 

    Rectangle drawSource = {sourceX, sourceY, 16, 16};
    Rectangle drawDest = {x, y, 32, 32};

    assignTile(sourceX, sourceY);

    DrawTexturePro(tileset, drawSource, drawDest, {0, 0}, 0, WHITE);
    
    DrawRectangleLines(x, y, size, size, BLUE);

    }}
}



void worldGen() {
    createGrid(GRID_SIZE);
   
    loadTileset();
}