#pragma once
#include "Player.h"
#include "GhostSpawner.h"
class Map{
    public:
      Map(EntityManager*);
      ~Map();
      void addBoundBlock(BoundBlock*);
      void addEntity(Entity*);
      void setPlayer(Player*);
      Player* getPlayer();
      void setGhostSpawner(GhostSpawner*);
      void tick();
      void render();
      void keyPressed(int key);
		  void mousePressed(int x, int y, int button);
		  void keyReleased(int key);

    private:
      EntityManager *entityManager;
      Player *player;
      GhostSpawner* gs;
};