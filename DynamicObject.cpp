#include "DynamicObject.h"
DynamicObject::DynamicObject(){}
DynamicObject::~DynamicObject(){}
DynamicObject::DynamicObject(Position position){
    this->position=position;
    this->speedControl=2;
    this->currentFrame=1;
}
bool DynamicObject::hasDestination(){
    return !this->moveQueue.empty();
}
//potential problems with the fact that after front temp might cease to exist? not sure how this works
Position DynamicObject::moveNext(){
    Position temp;
    if(this->currentFrame%this->speedControl==0){
        temp=this->moveQueue.front();
        this->moveQueue.pop();
    }
    else {
        temp=this->position;
    }
    this->position=temp;
    incrementCurrentFrame();
    return temp;
}
void DynamicObject::incrementCurrentFrame(){
    this->currentFrame++;
}
void DynamicObject::setMoveQueue(std::queue<Position> moveQueue){
    this->moveQueue=moveQueue;
}
void DynamicObject::setSpeedControl(int i){
    this->speedControl=i;
}
