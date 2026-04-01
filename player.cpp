//
// Created by TristanAckermann on 01.04.2026.
//

#include "player.h"
#include "raylib.h"


Player::Player() {
    position ={400.0f, 400.0f};
    velocity ={0.0f, 0.0f};

    collisionBox = { position.x, position.y , 40.0f, 40.0f };
    speed = 300.0f;
    jumpForce = 300.0f;

    health = 100.0f;
    maxHealth = 100.0f;
    mana = 0;

    dashTimer = 0.0f;
    dashForce = 900.0f;

    isGrounded = false;
    isDashing = false;
    canDoubleJump = true;
    isFacingLeft = false;
    isFacingRight = true;





}

void Player::Update(float deltaTime) {

    // 1. Reset
    velocity.x = 0.0f;

    // 2. Tasten und Fähigkeiten berechnen
    MoveRight(deltaTime);
    MoveLeft(deltaTime);

    // Der Dash managet jetzt seine eigene Logik und überschreibt die velocity!
    Dasch(deltaTime);

    // 3. GANZ AM SCHLUSS: Die Physik anwenden!
    position.x += velocity.x * deltaTime;

    // 4. Hitbox nachziehen
    collisionBox.x = position.x;
    collisionBox.y = position.y;

    // 5. Unverwundbarkeit
    if (invincibilityTimer > 0 ) {
        invincibilityTimer -= deltaTime;
    }

}

void Player::Draw() {
    Color playerColor = GREEN;

    if (invincibilityTimer > 0) {
        playerColor = RED;
    }

    DrawRectangleRec(collisionBox, playerColor);

}

void Player::TakeDamage(int amount) {
    if (invincibilityTimer > 0) {
        health -= amount;
        invincibilityTimer -= 1.5f;
    }

}

void Player::MoveRight (float deltaTime) {
    if (IsKeyDown(KEY_D)) {
        velocity.x = speed;
        isFacingRight = true;
        isFacingLeft = false;

    }
}

void Player::MoveLeft(float deltaTime) {
    if (IsKeyDown(KEY_A)) {
        velocity.x = -speed;
        isFacingLeft = true;
        isFacingRight = false;
    }
}

void Player::Dasch(float deltaTime) {
    if (IsKeyPressed(KEY_E) && dashTimer <= 0.0f) {
        dashTimer = 0.2f;
    }
    if (dashTimer > 0.0f) {
        dashTimer -= deltaTime;

        if (isFacingRight) {
            velocity.x = dashForce;
        } else {
            velocity.x -= dashForce;
        }
    }
}
