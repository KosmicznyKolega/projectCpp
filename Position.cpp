#include "Position.h"
Position::Position(){
    x=-1;
    y=-1;
}
Position::Position(int x, int y){
    this->x=x;
    this->y=y;
}
Position::~Position(){
}
int Position::getX(){
    return this->x;
}
int Position::getY(){
    return this->y;
}
void Position::setX(int x){
    this->x=x;
}
void Position::setY(int y){
    this->y=y;
}