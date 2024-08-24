#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"

class Character {
private:
   
    float speed;
    Texture2D sprite;
    Rectangle source;
    Rectangle dest;

    int currentFrame;
    int frameCount;
    
    float animationTimer;
    float frameTime;
    bool facingLeft;

public:
 Vector2 position;
 float frameWidth;
    Character(float x, float y);
    ~Character();

    void Update(float deltaTime);
    void UpdateAnimation(float deltaTime);
    void Draw();
    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();

    Vector2 GetPosition() const;
};

#endif // CHARACTER_H