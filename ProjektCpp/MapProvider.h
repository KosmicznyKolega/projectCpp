#ifndef MAP_PROVIDER_H
#define MAP_PROVIDER_H
#include "StaticObject.h"
#include "Wall.h"
#include "WinningSpace.h"
#include <random>
#include <vector>
class MapProvider {
	public:
		MapProvider();
		~MapProvider();
		std::vector<StaticObject> getMapOfStaticObjects();
	private:
		std::vector<StaticObject> mapOfStaticObjects;
};
#endif MAP_PROVIDER_H