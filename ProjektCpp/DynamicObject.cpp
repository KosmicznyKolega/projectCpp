#include "DynamicObject.h"
#include <iostream>
DynamicObject::DynamicObject() : position(Position()), moveQueue(std::deque<Position>()), speedControl(4),currentFrame(1), rect(sf::RectangleShape(sf::RectangleShape(sf::Vector2f(50.0, 50.0)))) {
    //this->texture.loadFromFile("potwor.png");
    //this->sprite.setTexture(this->texture);
    this->rect.setFillColor(sf::Color::Red);

}
DynamicObject::DynamicObject(const DynamicObject& dyn){
    this->position = dyn.getPosition();
    this->rect = dyn.getSprite();
    this->moveQueue = dyn.getMoveQueue();
    this->currentFrame = dyn.getCurrentFrame();
    this->speedControl = dyn.getSpeedControl();
}
DynamicObject& DynamicObject::operator=(const DynamicObject& dyn)
{
    if (this != &dyn) {
        this->position = dyn.getPosition();
        this->rect = dyn.getSprite();
        this->moveQueue = dyn.getMoveQueue();
        this->currentFrame = dyn.getCurrentFrame();
        this->speedControl = dyn.getSpeedControl();
    }
    return *this;
}
DynamicObject::~DynamicObject(){}
bool DynamicObject::hearsPlayer(Position positionOfPlayer)
{
   
        if (abs(positionOfPlayer.getX() - this->position.getX()) <= 20 && abs(positionOfPlayer.getY() - this->position.getY()) <= 20) {
            return true;
        }
        return false;
   
}
DynamicObject::DynamicObject(Position position) : position(position), moveQueue(std::deque<Position>()), speedControl(4), currentFrame(1),rect(sf::RectangleShape(sf::Vector2f(50.0,50.0))){
    //this->texture.loadFromFile("$(SolutionDir)/potwor.png");
    //this->sprite.setTexture(this->texture);
    this->rect.setFillColor(sf::Color::Red);
}
bool DynamicObject::hasDestination(){
    return !this->moveQueue.empty();
}
//potential problems with the fact that after front temp might cease to exist? not sure how this works
void DynamicObject::moveNext(){
    Position temp;
    if(this->currentFrame%this->speedControl==0 && this->hasDestination()){
        temp=this->moveQueue.front();
        this->moveQueue.pop_front();
    }
    else {
        temp=this->position;
    }
    this->position=temp;
    incrementCurrentFrame();
}
void DynamicObject::setRectSize()
{
    this->rect.setSize(sf::Vector2f(50, 50));
}
void DynamicObject::incrementCurrentFrame(){
    this->currentFrame++;
}
void DynamicObject::setMoveQueue(std::deque<Position> moveQueue){
    this->moveQueue=moveQueue;
}
void DynamicObject::setSpeedControl(int i){
    this->speedControl=i;
}
Position DynamicObject::getPosition() const {
    return this->position;
}

sf::RectangleShape DynamicObject::getSprite() const
{
    return this->rect;
}

void DynamicObject::moveRand()
{
    srand(time(NULL));
    int r = rand() % 4;
    int x = 0;
    int y = 0;
    switch (r) {
        case 0:
            x = 0;
            y = 1;
            break;
        case 1:
            x = 1;
            y = 0;
            break;
        case 2:
            x = 0;
            y = -1;
            break;
        case 3:
            x = -1;
            y = 0;
            break;
    }
    Position pos = Position(this->getPosition().getX() + x, this->getPosition().getY() + y);
    if (pos.getX() >= 0 && pos.getY() >= 0 && pos.getX() <= 119 && pos.getY() <= 119) {
        std::deque<Position> deq;
        deq.push_back(pos);
        this->setMoveQueue(deq);
    }
}

void DynamicObject::setSpritePos(int x, int y)
{
    this->rect.setPosition(x, y);
}

int DynamicObject::getCurrentFrame() const
{
    return this->currentFrame;
}

std::deque<Position> DynamicObject::getMoveQueue() const
{
    return this->moveQueue;
}

int DynamicObject::getSpeedControl() const
{
    return this->speedControl;
}
