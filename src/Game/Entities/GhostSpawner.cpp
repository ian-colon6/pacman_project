#include <iterator>
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

}
//------------------------------------------------------------------------------------------------------------------------------------

void GhostSpawner::tick(){
    std::vector<string> colors;
    colors.push_back("red");
    colors.push_back("pink");
    colors.push_back("cyan");
    colors.push_back("orange");

    if(em->ghosts.size() < 4 || em->normal_ghosts < 4){
        if(spawnCounter == 0){
            spawnGhost(colors[ofRandom(4)]);
            spawnCounter = 30*5;
            em->normal_ghosts++;
        }else{
            spawnCounter--;
        }
    }

    if(player_score == 500 && rGhost_detector == false){
        RandomGhostSpawn();
    }//Spawns the random ghost if there aren't any and player has 500
    if(player_score > 500 && em->num_of_random == 0){ 
        RandomGhostSpawn();
    }//Also spawns the random ghost if player has score > 500 and eliminated the first one
    
}
void GhostSpawner::spawnGhost(string color){
    Ghost* g = new Ghost(x,y,width-2,height-2,sprite,em, color);
    em->ghosts.push_back(g);

}

void GhostSpawner::SpawnRandom(int x, int y, string color){
    RandomGhost* r_g = new RandomGhost(x, y, width-2, height-2, sprite, em, color);
    em->ghosts.push_back(r_g);
    em->num_of_random++;
}

void GhostSpawner::RandomGhostSpawn(){

    int random_pos = ofRandom(em->entities.size());
    std::vector<string> colors_for_r = {"red", "cyan", "orange", "pink"};

    if(dynamic_cast<Dot*>(em->entities[random_pos])){

        int random_c = ofRandom(colors_for_r.size()); //selects a random color from the vector "colors"
        random_color = colors_for_r[random_c]; //stores the random color

        int X = em->entities[random_pos]->getX();
        int Y = em->entities[random_pos]->getY();
        em->entities[random_pos]->remove = true;
        SpawnRandom(X, Y, random_color);
        rGhost_detector = true;
    }
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

EntityManager* GhostSpawner::getEntManager(){
    return em;
}