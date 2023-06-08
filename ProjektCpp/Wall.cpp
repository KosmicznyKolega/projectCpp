#include "Wall.h"
Wall::Wall(Position position) : StaticObject(position){
    this->isSolid=true;/*
    this->texture.loadFromFile("sciana.png");
    this->sprite.setTexture(this->texture);*/
    this->rect.setFillColor(sf::Color::Black);
}
Wall::Wall(const Wall& wall)  {

    this->connections = wall.canPassTo();
    this->rect = wall.getSprite();
    this->isSolid = wall.getIsSolid();
    this->position = wall.getPosition();
    this->win = wall.didWin();

}
Wall& Wall::operator=(const Wall& wall)
{
    if (this != &wall) {
        this->connections = wall.canPassTo();
        this->rect = wall.getSprite();
        this->isSolid = wall.getIsSolid();
        this->position = wall.getPosition();
        this->win = wall.didWin();
    }
    return *this;
}
Wall::Wall() : StaticObject() { 
    this->isSolid = true; 
    this->rect.setFillColor(sf::Color::Black);
}
StaticObject& Wall::toStatOb() {
    return static_cast<StaticObject&>(*this);
}
//after this make sure to run setConnections from GameMap on this and all StaticObjects connected
void Wall::destroySelf(){
    this->isSolid=false;
}