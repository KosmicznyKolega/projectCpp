#ifndef WINNING_SPACE_H
#define WINNING_SPACE_H
#include "StaticObject.h"
class WinningSpace : public StaticObject{
    public:
        WinningSpace(const WinningSpace& win);
        WinningSpace();
        WinningSpace& operator=(const WinningSpace& ws);
        WinningSpace(Position position);
        StaticObject& toStatOb();
        bool didWin();
};
#endif WINNING_SPACE_H