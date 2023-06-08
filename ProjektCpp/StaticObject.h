#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H
#include "Position.h"
#include "SFML/Graphics.hpp"
#include <windows.h>
#include <vector>
class StaticObject{
    public:
        StaticObject(const StaticObject& statObj);
        StaticObject(Position pos);
        StaticObject& operator=(const StaticObject& statObj);
        StaticObject();
        ~StaticObject();
        void setRectSize();
        void setRectColor(sf::Color color);
        void setConnections(std::vector<Position> connections);
        bool getIsSolid() const;
        std::vector<Position> canPassTo() const;
        bool didWin() const;
        Position getPosition() const;
        sf::RectangleShape getSprite() const;
        void setSpritePos(int x, int y);
        void destroySelf();
    protected:
        bool win;
        Position position;
        std::vector<Position> connections;
        bool isSolid;
        sf::RectangleShape rect;
};
#endif STATIC_OBJECT_H