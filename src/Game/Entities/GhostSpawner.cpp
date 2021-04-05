#pragma once
#include "GhostSpawner.h"
#include "Ghost.h"
#include "RandomGhost.h"
#include "Dot.h"

GhostSpawner::GhostSpawner(int x, int y, int width, int height, EntityManager* em, ofImage sprite) : Entity(x, y, width, height){
    this->em = em;
    this->sprite = sprite;
    spawnGhost("red");
    spawnGhost("pink");
    spawnGhost("cyan");
    spawnGhost("orange");

    std::vector<string> random_color = {"red", "pink", "cyan", "orange"};
    int position_color = ofRandom(4);
    RandomSpawner(random_color[position_color]);

}

void GhostSpawner::tick(){
    std::vector<string> colors;
    colors.push_back("red");
    colors.push_back("pink");
    colors.push_back("cyan");
    colors.push_back("orange");

    if(em->ghosts.size()<4){
        if(spawnCounter == 0){
            spawnGhost(colors[ofRandom(4)]);
            spawnCounter = 30*5;
        }else{
            spawnCounter--;
        }
    }
    if(em->random_ghost.size() < 1){
        RandomSpawner(colors[ofRandom(4)]);
    }
}
void GhostSpawner::spawnGhost(string color){
    Ghost* g = new Ghost(x,y,width-2,height-2,sprite,em, color);
    em->ghosts.push_back(g);
}

void GhostSpawner::RandomSpawner(string color){
    RandomGhost* r_g = new RandomGhost(x,y,width-2, height-2, sprite, em, color);
    em->random_ghost.push_back(r_g);
}

void GhostSpawner::keyPressed(int key){
    if(key == 'g'){
        std::vector<string> ghosts  = {"red", "cyan", "pink", "orange"};
        std::vector<int> assign;

        for(int i = 0; i < ghosts.size(); i++){
            assign.push_back(ofRandom(0,3));
            spawnGhost(ghosts[assign[i]]);
        }
        
    }
}