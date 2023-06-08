#include "Position.h"
Position::Position(){
    x=-1;
    y=-1;
}
Position::Position(int x, int y) : x(x), y(y){}
Position::~Position(){
}
int Position::getX() const{
    return x;
}
int Position::getY() const{
    return y;
}
void Position::setX(int x){
    this->x=x;
}
void Position::setY(int y){
    this->y=y;
}
Position::Position(const Position& position) {
    this->x = position.getX();
    this->y = position.getY();
}

//bool Position::operator==(const Position& pos)
//{
//    return (this->getX() == pos.getX() && pos.getY() == this->getY());
//}
Position& Position::operator=(const Position& pos)
{
    if (this != &pos) {
        this->x = pos.getX();
        this->y = pos.getY();
    }
    return *this;
}

