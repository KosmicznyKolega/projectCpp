#ifndef PLAYER_H
#define PLAYER_H
#include "DynamicObject.h"
class Player : public DynamicObject{
    public:
        Player();
        Player& operator=(const Player& play);
        Player(Position pos);
        Player(const Player& play);
        DynamicObject& toDyn();
};
#endif PLAYER_H