#pragma once
#include "RandomPower.h"
//#include "Player.h"
#include "Dot.h"
#include "EntityManager.h"
#include "Entity.h"

RandomPower::RandomPower(EntityManager* pwr_up){
    this->pwr_up = pwr_up;
}

void RandomPower::enable(){

    random_pos = ofRandom(0, pwr_up->entities.size() + 1);
    //arbitrary entity
    
    for(Entity* organism : pwr_up->entities){

        if(dynamic_cast<Dot*>(organism)){

            
            int plr_x = pwr_up->entities[random_pos]->getX();
            int plr_y = pwr_up->entities[random_pos]->getY();

            //replaces current player position to the arbitrary position and removes the object
            pwr_up->entities[random_pos]->remove = true;
            pwr_up->X = plr_x;
            pwr_up->Y = plr_y;

        }
    }
}