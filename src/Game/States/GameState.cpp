#include "GameState.h"
#include "Entity.h"
#include "RandomGhost.h"

GameState::GameState() {
	ofSoundSetVolume(0.5);
	music.load("music/pacman_chomp.wav");
	ofSoundSetVolume(0.7);
	persona.load("music/Last_Surprise.wav");
	mapImage.load("images/map1.png");
	map = MapBuilder().createMap(mapImage);
}
void GameState::tick() {
	if(!music.isPlaying()){

		music.play();
	}
	if(!persona.isPlaying()){
		persona.setPaused(false);
		persona.setLoop(true);
		persona.play();
	}
	map->tick();
	if(map->getPlayer()->getHealth() == 0){
		setFinished(true);
		setNextState("over");
		map->getPlayer()->setHealth(3);
		finalScore = map->getPlayer()->getScore();
		map->getPlayer()->setScore(0);
	}
	else if (map->getPlayer()->getScore() == 4500){
		setFinished(true);
		setNextState("win");
		map->getPlayer()->setHealth(3);
		finalScore = map->getPlayer()->getScore();
		map->getPlayer()->getScore();
	}
	else if(getNextState() == "pause"){
		setNextState("pause");
		setFinished(true);
		persona.stop();
	}

	score = map->getPlayer()->getScore();
	map->getGhostSpawner()->player_score = score;
}
void GameState::render() {
	map->render();
}

void GameState::keyPressed(int key){
	map->keyPressed(key);
	if(key == 'y'){
		setFinished(true);
		setNextState("win");
		map->getPlayer()->setHealth(3);
		finalScore = map->getPlayer()->getScore();
		map->getPlayer()->getScore();
		persona.setPaused(true);
	}
	else if(key == 'p'){
		PAUSE = true;
		setNextState("pause");
		setFinished(true);
		persona.stop();
	}
	else if(key == 'r'){
		//Press r if you want to listen to a different track while on gamestate
		ofSoundSetVolume(0.7);
		persona.load("music/Rivers_in_the_Desert.wav");
	}
	else if(key == 'l'){
		ofSoundSetVolume(0.7);
		persona.load("music/Last_Surprise.wav");
	}
}

void GameState::mousePressed(int x, int y, int button){
	map->mousePressed(x, y, button);
}

void GameState::keyReleased(int key){
	map->keyReleased(key);
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
	map = MapBuilder().createMap(mapImage);
	if(PAUSE){
		delete map;
		map = MapBuilder().createMap(mapImage);
	}
}

int GameState::getFinalScore(){
	return finalScore;
}

GameState::~GameState(){
	delete map;
}