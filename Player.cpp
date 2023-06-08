#include "Player.h"
Player::Player(Position position){
    this->position=position;
    this->speedControl=3;
    this->currentFrame=1;
}