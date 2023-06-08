#include "MapProvider.h"
MapProvider::MapProvider(){
	mapOfStaticObjects = std::vector<StaticObject>();
	int j = 120;
	for (int i = 0;i < 120 * 120;i++) {
		if(j<120 || i%12==0) {
			Wall w(Position((int)(i / 120), i % 120));
			mapOfStaticObjects.push_back(w.toStatOb());
		}
		else {
			StaticObject s(Position((int)(i / 120), i % 120));
			mapOfStaticObjects.push_back(s);
		}
		j--;
		if (j == 0) {
			j = 120*12;
		}
		
	}
	WinningSpace x = WinningSpace(Position(104,116));
	mapOfStaticObjects[12596] = x.toStatOb();
	srand(time(NULL));
	int r;
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			StaticObject s1(Position(j * 12 +6, (i+1) * 12));
			mapOfStaticObjects[s1.getPosition().getY() + s1.getPosition().getX() * 120] = s1;
				StaticObject s(Position((1 + j) * 12, i * 12 +6 ));
				mapOfStaticObjects[s.getPosition().getY() + s.getPosition().getX() * 120] = s;
		}
	}
}
MapProvider::~MapProvider() {}
std::vector<StaticObject> MapProvider::getMapOfStaticObjects() {
	return this->mapOfStaticObjects;
}