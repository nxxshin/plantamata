#include "Character.h"
#include <iostream>

Character::Character(float x, float y) : 
    position{x, y},
    speed{5.0f},
    frameCount{5},
    frameWidth{32},
    currentFrame{0},
    animationTimer{0.0f},
    frameTime{0.1f},
    facingLeft{false}
{
    sprite = LoadTexture("resources/character/maincebolla-sheet.png");
    source = {0, 0, static_cast<float>(frameWidth), static_cast<float>(frameWidth)};
    dest = {x, y, static_cast<float>(frameWidth * 2), static_cast<float>(frameWidth * 2)};
}

Character::~Character() {
    UnloadTexture(sprite);
}

void Character::Update(float deltaTime) {
    bool isMoving = false;

    if (IsKeyDown(KEY_LEFT)) {
        position.x -= speed * deltaTime * 50;
        facingLeft = true;
        isMoving = true;
    } 
    if (IsKeyDown(KEY_RIGHT)) {
        position.x += speed * deltaTime * 50;
        facingLeft = false;
        isMoving = true;
    }  
    if (IsKeyDown(KEY_DOWN)) {
        position.y += speed * deltaTime * 50;
        isMoving = true;
    }  
    if (IsKeyDown(KEY_UP)) {
        position.y -= speed * deltaTime * 50;
        isMoving = true;
    }

    if (isMoving) {
        UpdateAnimation(deltaTime);
    }

    // Update destination rectangle
    dest.x = position.x;
    dest.y = position.y;
}

void Character::UpdateAnimation(float deltaTime) {
    animationTimer += deltaTime;
    if (animationTimer >= frameTime) {
        currentFrame = (currentFrame + 1) % frameCount;
        source.x = static_cast<float>(currentFrame * frameWidth);
        animationTimer -= frameTime;
    }
}

void Character::Draw() {
    Rectangle drawSource = source;
    Rectangle drawDest = dest;

    if (!facingLeft) {
        drawSource.width = -source.width;  // Flip the source rectangle
    }

    DrawTexturePro(sprite, drawSource, drawDest, {0, 0}, 0, WHITE);

    // // Debug drawing
    // DrawRectangleLines(dest.x, dest.y, dest.width, dest.height, RED);
    // DrawCircle(dest.x, dest.y, 3, BLUE);  // Origin point
}

Vector2 Character::GetPosition() const {
    return position;
}