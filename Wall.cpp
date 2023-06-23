#include "Wall.h"
Wall::Wall(Position position){
    this->position=position;
    this->isSolid=true;
}
//after this make sure to run setConnections from GameMap on this and all StaticObjects connected
void Wall::destroySelf(){
    this->isSolid=false;
}