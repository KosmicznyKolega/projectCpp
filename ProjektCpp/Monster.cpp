#include "Monster.h"
#include <cstdlib>
//hearing distance == 20 <-- change in this function vvv
bool Monster::hearsPlayer(Position position) {
    if(abs(position.getX()-this->position.getX())<=20 && abs(position.getY()-this->position.getY())<=20){
        return true;
    }
    return false;
}
Monster::Monster() : DynamicObject(){}
Monster::Monster(Position position) : DynamicObject(position) {}
Monster& Monster::operator=(const Monster& m)
{
    if (this != &m) {
        this->position = m.getPosition();
        this->rect = m.getSprite();
        this->moveQueue = m.getMoveQueue();
        this->currentFrame = m.getCurrentFrame();
        this->speedControl = m.getSpeedControl();
    }
    return *this;
}
Monster::Monster(const Monster& m)  {
    this->position = m.getPosition();
    this->rect = m.getSprite();
    this->moveQueue = m.getMoveQueue();
    this->currentFrame = m.getCurrentFrame();
    this->speedControl = m.getSpeedControl();
}

DynamicObject& Monster::toDyn() {
    return static_cast<DynamicObject&>(*this);
}