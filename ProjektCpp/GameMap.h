#ifndef GAME_MAP_H
#define GAME_MAP_H
#include "StaticObject.h"
#include "DynamicObject.h"
#include <deque>
#include <stack>
#include <vector>
#include <iostream>
class GameMap{
    public:
        GameMap();
        ~GameMap();
        void initMap(std::vector<StaticObject> gameMap);
        void changeVisibleMap();
        std::vector<DynamicObject>& getDynamicObjects();
        std::deque<Position> moveToMonster(Position pos);
        std::deque<Position> moveToDFS(Position pos, int who);
        void setConnections(Position pos);
        void destroyAt(Position pos);
        std::vector<StaticObject>& getGameMap();
        std::vector<StaticObject*> getVisibleMap();
        std::deque<Position> dfsHelper(Position start, std::vector<bool>& visited, std::deque<Position>& path, Position target, int steps);
        std::vector<int> bfs(Position start, Position target, int maxSteps);
        std::deque<Position> reconstructPath(const std::vector<int>& previous, int target);
    private:
        std::vector<StaticObject> gameMap;
        std::vector<DynamicObject> dynamicObjects;
        std::vector<StaticObject*> visibleMap;
        // map boudries, from 0 to size-1 in both directions (x,y)
        int size = 120;
        int visibility = 15;
};
#endif GAME_MAP_H