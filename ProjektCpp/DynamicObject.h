#ifndef DYNAMIC_OBJECT_H
#define DYNAMIC_OBJECT_H
#include "Position.h"
#include <SFML/Graphics.hpp>
#include <deque>
#include <random>
// #define HEARING_DISTANCE=20;
class DynamicObject{
    public:
        virtual bool hearsPlayer(Position positionOfPlayer);
        DynamicObject(Position pos);
        DynamicObject();
        DynamicObject(const DynamicObject& dyn);
        DynamicObject& operator=(const DynamicObject& dyn);
        ~DynamicObject();
        bool hasDestination();
        void moveNext();
        void setRectSize();
        void incrementCurrentFrame();
        void setMoveQueue(std::deque<Position> moveQueue);
        void setSpeedControl(int i);
        Position getPosition() const;
        sf::RectangleShape getSprite() const;
        void moveRand();
        void setSpritePos(int x,int y);
        int getCurrentFrame() const;
        std::deque<Position> getMoveQueue() const;
        int getSpeedControl() const;
    protected:
        Position position;
        std::deque<Position> moveQueue;
        //which frame to skip to control speed if(currentFrame%speedControl==0) dont move, so 1 is move always 2 is move every other frame and 3 is every 3 frames
        int speedControl;
        //counter with which to see wether to move or not
        int currentFrame;
        sf::RectangleShape rect;
};
#endif DYNAMIC_OBJECT_H