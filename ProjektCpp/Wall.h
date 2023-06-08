#ifndef WALL_H
#define WALL_H
#include "StaticObject.h"
class Wall : public StaticObject{
        public:
        Wall(Position pos);
        Wall(const Wall& wall);
        Wall& operator=(const Wall& wall);
        Wall();
        StaticObject& toStatOb();
        void destroySelf();
};
#endif WALL_H