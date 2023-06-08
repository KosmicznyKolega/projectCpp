#include "Player.h"
Player::Player() : DynamicObject(){
    this->rect.setFillColor(sf::Color::Green);
    this->speedControl = 5;
    this->currentFrame = 1;
}
Player& Player::operator=(const Player& play)
{
    if (this != &play) {
        this->position = play.getPosition();
        this->rect = play.getSprite();
        this->moveQueue = play.getMoveQueue();
        this->currentFrame = play.getCurrentFrame();
        this->speedControl = play.getSpeedControl();
    }
    return *this;
}
Player::Player(Position position) : DynamicObject(position){
    this->speedControl=5;
    this->currentFrame=1;
    this->rect.setFillColor(sf::Color::Green);

}
Player::Player(const Player& p) : DynamicObject(p.getPosition()){
    this->speedControl = 5;
    this->currentFrame = 1;    
    this->rect.setFillColor(sf::Color::Green);
}
DynamicObject& Player::toDyn() {
    return static_cast<DynamicObject&>(*this);
}