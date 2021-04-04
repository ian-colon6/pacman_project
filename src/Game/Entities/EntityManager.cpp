#include "EntityManager.h"
#include "Ghost.h"
#include "RandomGhost.h"
#include "Player.h"
void EntityManager::tick(){
    if(killable){
        killableCounter--;
        if (killableCounter == 0){
            killable = false;
            for(Entity* entity:ghosts){
                Ghost* ghost = dynamic_cast<Ghost*>(entity); 
                ghost->setKillable(false);
                RandomGhost* r_ghost = dynamic_cast<RandomGhost*>(entity);
                r_ghost->setKillable(false);
            }
        }
    }
    std::vector<int> toRemove;
    
    for(int i=0;i<entities.size();i++){
        if(!entities[i]->remove){
            entities[i]->tick();

        }else{
            toRemove.push_back(i);
        }
    }
    for(unsigned int removable: toRemove){
        Entity* entityPointer = *(entities.begin() + removable);
        entities.erase(entities.begin() + removable);
        delete entityPointer;
    }
    toRemove.clear();
    for(BoundBlock* BoundBlock: BoundBlocks){
        BoundBlock->tick();
    }
    for(int i=0;i<ghosts.size();i++){
        if(!ghosts[i]->remove){
            ghosts[i]->tick();

        }else{
            toRemove.push_back(i);
        }
    }
    for(unsigned int removable: toRemove){
        Ghost* entityPointer = dynamic_cast<Ghost*>(*(ghosts.begin() + removable));
        ghosts.erase(ghosts.begin() + removable);
        delete entityPointer;
    }
}

void EntityManager::render(){
    for(Entity* entity: entities){
        entity->render();
        Player* player1 = dynamic_cast<Player*>(entity);
        RandomGhost* random_entity = dynamic_cast<RandomGhost*>(entity);
        
        for(int i = 0; i < entities.size(); i++){

            Entity* position = entities[ofRandom(0, i)];

            if(dynamic_cast<Dot*>(position)){
                
                rand_position.push_back(position);
                break;
            }
            else{
                continue;
            }

        }

        if(player1->getScore() >= 500){
            random_entity->render();
        }
    }
    for(BoundBlock* BoundBlock: BoundBlocks){
        BoundBlock->render();
    }
    for(Entity* ghost: ghosts){
        ghost->render();
    }
}

void EntityManager::setKillable(bool k){
    killable = true;
    killableCounter=30*10;
    for(Entity* entity:ghosts){
        Ghost* ghost = dynamic_cast<Ghost*>(entity); 
        ghost->setKillable(true);
        RandomGhost* R_ghost = dynamic_cast<RandomGhost*>(entity);
        R_ghost->setKillable(true);
    }
}

EntityManager::~EntityManager(){
    for(Entity* e: BoundBlocks){
        delete e;

    }
    for(Entity* e: ghosts){
        Ghost* ghostPointer = dynamic_cast<Ghost*>(e);
        delete e;
        RandomGhost* r_ghost_ptr = dynamic_cast<RandomGhost*>(e);
        delete e;
    }
    for(Entity* e: entities){
        delete e;
    }
    BoundBlocks.clear();
    ghosts.clear();
    entities.clear();
}