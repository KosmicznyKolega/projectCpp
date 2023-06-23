#include "Monster.h"
#include <cstdlib>
//hearing distance == 20 <-- change in this function vvv
bool Monster::hearsPlayer(Position position){
    if(abs(position.getX()-this->position.getX())<=20 || abs(position.getY()-this->position.getY())<=20){
        return true;
    }
    return false;
}
