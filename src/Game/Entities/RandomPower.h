#include "EntityManager.h"
#include "PowerUp.h"

class RandomPower : public PowerUp{

    private:
        EntityManager *pwr_up;
        int random_pos; 

    public:
        RandomPower(EntityManager*);
        void enable();

};