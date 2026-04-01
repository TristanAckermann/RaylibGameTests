//
// Created by TristanAckermann on 01.04.2026.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H
#include <string>
#include <vector>

#include "raylib.h"


class Player {
public:
    Player();

    void Update(float deltaTime);
    void Draw();

    void TakeDamage(int amount);
    void AddMana(int amount);

    Rectangle GetCollisionBox() const {return collisionBox;}
    Vector2 GetPosition() const { return position; }
    Vector2 GetVelocity() const { return velocity; }

    void SetPosition(Vector2 newPosition) { position = newPosition; }
    void SetVelocity(Vector2 newVelocity) { velocity = newVelocity; }
    void MoveRight(float deltaTime);
    void MoveLeft(float deltaTime);
    void Dasch(float deltaTime);

private:
    Vector2 velocity;
    Vector2 position;

    float speed;
    float jumpForce;

    float dashTimer;
    float dashForce;

    Rectangle collisionBox;

    int health;
    int maxHealth;
    int mana;


    float invincibilityTimer;
    float coyoteTimeCounter;
    float dashCooldown;

    bool isGrounded;
    bool isDashing;
    bool canDoubleJump;
    bool isFacingRight;
    bool isFacingLeft;
};



#endif //UNTITLED_PLAYER_H
