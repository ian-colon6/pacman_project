#pragma once
#include "Animation.h"
#include "PowerUp.h"
#include "RandomPower.h"
#include "EntityManager.h"

class Player: public Entity{

    private:
        int spawnX, spawnY;
        int health=3;
        int score=0;
        bool canMove;
        int speed = 8;
        bool walking = false;
        FACING facing = DOWN;
        ofImage up, down, left, right;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        EntityManager* em;
        PowerUp* the_power;
        RandomPower* random_pwr;

    public:
        Player(int, int, int , int, EntityManager*);
        ~Player();
        powerUp();
        int getHealth();
        void setHealth(int);
        int getScore();
        void setScore(int);
        void setPosX(int);
        void setPosY(int);
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);
        void damage(Entity* damageSource);
        void mousePressed(int, int, int);
        void reset();
        void setFacing(FACING facing);
        void checkCollisions();
        void die();
};