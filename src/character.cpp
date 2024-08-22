#include "Character.h"
#include <iostream>

Character::Character(float x, float y) : position{x, y}, speed{5.0f} {
    // Load character sprite
    // sprite = LoadTexture("path/to/your/character/sprite.png");
    sprite : DrawCircle(x,y, 5, WHITE);
}

Character::~Character() {
    // Unload character sprite
    UnloadTexture(sprite);
}

void Character::Update() {
    // Update character logic here
    // This could include checking for input, updating position, etc.
}

void Character::Draw() {
    sprite : DrawCircle(position.x,position.y, 5, WHITE);
    // Draw the character
    // DrawTextureV(sprite, position, WHITE);
}

void Character::MoveLeft() {
    // Implement left movement
    if (IsKeyDown(KEY_LEFT) == true) {
    position.x -= speed;
    } 
    // position.x -= speed;
}

void Character::MoveRight() {
    // Implement right movement
    position.x += speed;
}

void Character::MoveUp() {
    // Implement upward movement
    position.y -= speed;
}

void Character::MoveDown() {
    // Implement downward movement
    position.y += speed;
}

Vector2 Character::GetPosition() const {
    return position;
}