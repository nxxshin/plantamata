#include <iostream>
#include "raylib.h"

const int GRID_SIZE = 32;

struct Cell {
    float x;
    float y;
};

Cell grid[GRID_SIZE][GRID_SIZE];

void LoadTileSheet() {
Texture2D tilesheet = LoadTexture("resources/world/tilesheet.png");
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

void drawWorld() {

    float size = 32;
    Color color = LIGHTGRAY;

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
           float x =  grid[i][j].x;
           float y = grid[i][j].y;
    Vector2 position = {x,y};
    DrawRectangle(x,y, size, size, color); 
        DrawRectangleLines(x, y, size, size, BLUE);
    }}
}

void worldGen() {
    createGrid(GRID_SIZE);
}