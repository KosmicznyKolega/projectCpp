#include "Position.h"
class StaticObject{
    public:
        StaticObject(Position pos);
        StaticObject();
        ~StaticObject();
        void setConnections(Position* connections);
        bool getIsSolid();
        Position* canPassTo();
        virtual bool didWin();
    protected:
        Position position;
        Position connections[4] = {Position(),Position(),Position(),Position()};
        bool isSolid;
};