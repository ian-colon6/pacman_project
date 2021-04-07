#pragma once

#include "BoundBlock.h"

class EntityManager {

public:
	~EntityManager();
	std::vector<Entity*> entities;
	std::vector<BoundBlock*> BoundBlocks;
	std::vector<Entity*> ghosts;
	void tick();
	void render();
	void setKillable(bool);
	vector<Entity*> getEnts();
	void getPlayerScore();
	bool rGhost_detector = false;
	int num_of_random = 0;
	//Possible int for peekaboo
	int normal_ghosts = 4;
	int r_pwr_count = 0;
	int X;
	int Y;
	
	int dots_removed = 0;


private:
	bool killable = false;
	int killableCounter;
};