#ifndef MONSTER_H
#define MONSTER_H
#include "DynamicObject.h"
class Monster : public DynamicObject{
    public:
        bool hearsPlayer(Position positionOfPlayer) override;
        Monster();
        Monster(Position pos);
        Monster& operator=(const Monster& m);
        Monster(const Monster& play);
        DynamicObject& toDyn();
};
#endif MONSTER_H