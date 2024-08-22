#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"

class Character {
private:
    Vector2 position;
    float speed;
    Texture2D sprite;

public:
    Character(float x, float y);
    ~Character();

    void Update();
    void Draw();
    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();

    Vector2 GetPosition() const;
};

#endif // CHARACTER_H