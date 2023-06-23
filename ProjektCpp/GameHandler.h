#ifndef GAME_HANDLER_H
#define GAME_HANDLER_H
#include "GameMap.h"
#include "MapProvider.h"
#include "DynamicObject.h"
#include "Monster.h"
class GameHandler{
    public:
        GameHandler();
        ~GameHandler();
        //init map, player, monster and start the main game loop
        bool run();
    private:
        //GameMap gameMap;
        //MapDrawer mapDrawer;
        //MapProvider mapProvider;

};
#endif GAME_HANDLER_H