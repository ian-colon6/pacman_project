#pragma once
#include "State.h"
#include "Player.h"
#include "MapBuilder.h"

class GameState: public State{
    public: 
        GameState();
		~GameState();
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);
		int getFinalScore();
		void RandomGhostSpawn();
		bool rGhost_detector = false;
		int score = 0;
	
	private:
		ofSoundPlayer music;
		ofSoundPlayer persona;
		ofImage mapImage;
		Map* map;
		int finalScore=0;

};