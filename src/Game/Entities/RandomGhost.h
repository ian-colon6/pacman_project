#pragma once
#include "Ghost.h"
//#include "EntityManager.h"
//#include "Animation.h"
#include "Dot.h"


class RandomGhost : public Ghost{
    private:
        
        bool killable = false;
        FACING facing = UP;
        bool canMove = true;
        bool justSpawned = false;
        void checkCollisions();
        int speed = 3;
        EntityManager* em;
        Animation* killableAnim;

    public:

        RandomGhost(int, int, int, int, ofImage, EntityManager*, string);
        ~RandomGhost();
        void tick();
        void render();
        bool getKillable();
        void setKillable(bool);
};