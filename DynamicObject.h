#include "Position.h"
#include <queue>
// #define HEARING_DISTANCE=20;
class DynamicObject{
    public:
        DynamicObject(Position pos);
        DynamicObject();
        ~DynamicObject();
        bool hasDestination();
        Position moveNext();
        void incrementCurrentFrame();
        void setMoveQueue(std::queue<Position> moveQueue);
        void setSpeedControl(int i);
    protected:
        Position position;
        std::queue<Position> moveQueue;
        //which frame to skip to control speed if(currentFrame%speedControl==0) dont move, so 1 is move always 2 is move every other frame and 3 is every 3 frames
        int speedControl;
        //counter with which to see wether to move or not
        int currentFrame;
};