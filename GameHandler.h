#include "StaticObject.h"
#include "DynamicObject.h"
#include "EntityType.h"
class GameHandler{
    public:
        GameHandler();
        ~GameHandler();
        //init map, player, monster and start the main game loop
        void run();
    private:
        //move all characters (the player first);
        void move();
        void updateMapDrawerAndRender();
        // either win 1, lose -1, or nothing happens 0
        int checkIfGameEnded();
        GameMap gameMap;
        MapDrawer mapDrawer;
        DynamicObject* dynamicObjects;

};