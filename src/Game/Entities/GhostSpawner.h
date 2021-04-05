#pragma once

#include "EntityManager.h"

class GhostSpawner: public Entity{
    public:
        GhostSpawner(int, int, int , int, EntityManager*, ofImage);
        void spawnGhost(string);
        void SpawnRandom(int, int, string);
        void RandomGhostSpawn();
        void keyPressed(int);
        void tick();
        EntityManager* getEntManager();
        string random_color;
        int player_score = 0;
        bool rGhost_detector = false;
    private:
        EntityManager* em;
        int spawnCounter = 30*5;
};