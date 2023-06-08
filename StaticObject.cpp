#include "StaticObject.h"
StaticObject::StaticObject(Position position){
    this->position=position;
    this->isSolid=false;
}
StaticObject::StaticObject(){}
StaticObject::~StaticObject(){}
bool StaticObject::didWin(){
    return false;
}
bool StaticObject::getIsSolid(){
    return isSolid;
}
Position* StaticObject::canPassTo(){
    return connections;
}
void StaticObject::setConnections(Position* connections){
    for (int i=0;i<4;i++){
        this->connections[i]=connections[i];
    }
}