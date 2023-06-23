#include "StaticObject.h"
#include "EntityType.h"
#include "DynamicObject.h"
#include <queue>
class GameMap{
    public:
        GameMap(DynamicObject* dynamicObjects, int size, int visibility);
        ~GameMap();
        //to zmienic bo nie przekazuje dynamicobjects :)
        StaticObject* returnVisibleMap();
        std::queue<Position> moveTo(EntityType eT,Position pos);
        void destroyAt(Position pos);
        void updateDynamicObjects(DynamicObject* dynamicObjects);
    private:
        StaticObject* gameMap;
        // map boudries, from 0 to size-1 in both directions (x,y)
        int size;
        //how big of a square is visible
        int visibility;
        DynamicObject* dynamicObjects;
};
