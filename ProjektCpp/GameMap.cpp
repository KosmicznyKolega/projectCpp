#include "GameMap.h"
#include "Monster.h"
#include "Player.h"
#include "Wall.h"
#include <queue>
GameMap::GameMap() {
	visibleMap = std::vector<StaticObject*>();
	for (int i = 0;i < 15 * 15;i++) {
		StaticObject z;
		visibleMap.push_back(&z);
	}
	dynamicObjects = std::vector<DynamicObject>();
	Monster mon = Monster(Position(62,62));
	this->dynamicObjects.push_back(mon.toDyn());
	Player pl = Player(Position(4, 4));
	this->dynamicObjects.push_back(pl.toDyn());
}

GameMap::~GameMap() {}
void GameMap::initMap(std::vector<StaticObject> gameMap){
	this->gameMap = gameMap;
	for (int row = 0; row < 120;row++) {
		for (int col = 0; col < 120;col++) {
			std::vector<Position> connections;
			int val = (row - 1) * 120 + col;
			if (row > 0 && !this->gameMap[val].getIsSolid()) {
				connections.push_back(Position(col, row - 1));
			}
			else {
				connections.push_back(Position());
			}
			val = (row) * 120 + col + 1;
			if (col < 119 && !this->gameMap[val].getIsSolid()) {
				connections.push_back(Position(col + 1, row));
			}
			else {
				connections.push_back(Position());
			}val = (row + 1) * 120 + col;
			if (row < 119 && !this->gameMap[val].getIsSolid()) {
				connections.push_back(Position(col, row + 1));
			}
			else {
				connections.push_back(Position());
			}
			val = (row) * 120 + col - 1;
			if (col > 0 && !this->gameMap[val].getIsSolid()) {
				connections.push_back(Position(col - 1, row));
			}
			else {
				connections.push_back(Position());
			}
			this->gameMap[(row * 120) + col].setConnections(connections);
		}
	}
}
//it can lag change later
void GameMap::changeVisibleMap() {
	Position position = this->dynamicObjects[1].getPosition();
	int x=0;
	int y=0;
	if (position.getX() < 7) {
		x = 0;
	}
	else if (position.getX() >= 112) {
		x = 105;
	}
	else {
		x = position.getX() - 7;
	}
	if (position.getY() < 7) {
		y = 0;
	}
	else if (position.getY() >= 112) {
		y = 105;
	}
	else {
		y = position.getY() - 7;
	}
	this->dynamicObjects[0].setSpritePos(-50, -50);
	this->dynamicObjects[1].setSpritePos(-50, -50);
	for (int row = 0; row < 15; row++) {
		for (int col = 0; col < 15;col++) {
			this->visibleMap[row * 15 + col] = &this->gameMap[(y + row) * 120 + col + x];
			this->gameMap[(y + row) * 120 + col + x].setRectSize();
			this->gameMap[(y + row) * 120 + col + x].setSpritePos((col % 15) * 50, (row % 15) * 50);
			if (this->dynamicObjects[0].getPosition().getX() == x+col && this->dynamicObjects[0].getPosition().getY() == y+row){
				this->dynamicObjects[0].setSpritePos((col % 15 )*50, (row % 15)*50);
				this->dynamicObjects[0].setRectSize();
			}
			else if (this->dynamicObjects[1].getPosition().getX() == x + col && this->dynamicObjects[1].getPosition().getY() == y + row) {
				 this->dynamicObjects[1].setSpritePos((col % 15) * 50, (row % 15) * 50);
				 this->dynamicObjects[1].setRectSize();

			}
		}
	}
}
std::vector<DynamicObject>& GameMap::getDynamicObjects(){
	return this->dynamicObjects;
}
void GameMap::setConnections(Position pos) {
	std::vector<Position> connections;
	int row = pos.getY();
	int col = pos.getX();
	int val = (row - 1) * 120 + col;
	if (row>0 && !this->gameMap[val].getIsSolid()) {
		connections.push_back(Position(col, row - 1));
	}
	else {
		connections.push_back(Position());
	}
	val = (row) * 120 + col + 1;
	if (col<119 && !this->gameMap[val].getIsSolid()) {
		connections.push_back(Position(col+1, row  ));
	}
	else {
		connections.push_back(Position());
	}
	val = (row+1) * 120 + col;
	if (row < 119 && !this->gameMap[val].getIsSolid()) {
		connections.push_back(Position(col, row + 1));
	}
	else {
		connections.push_back(Position());
	}
	val = (row) * 120 + col - 1;
	if (col > 0 && !this->gameMap[val].getIsSolid()) {
		connections.push_back(Position(col-1, row));
	}
	else {
		connections.push_back(Position());
	}
	val = (row) * 120 + col;
	this->gameMap[val].setConnections(connections);
}
void GameMap::destroyAt(Position pos) {
	int val = (pos.getY()) * 120 + pos.getX();
	this->gameMap[val].destroySelf();
		this->setConnections(pos);
		if (pos.getX() != 0) {
			this->setConnections(Position(pos.getX() - 1, pos.getY()));
		}
		if (pos.getY() != 0) {
			this->setConnections(Position(pos.getX(), pos.getY() - 1));
		}
		if (pos.getX() != 119) {
			this->setConnections(Position(pos.getX() + 1, pos.getY()));
		}
		if (pos.getY() != 119) {
			this->setConnections(Position(pos.getX(), pos.getY() + 1));
		}
}
std::vector<StaticObject>& GameMap::getGameMap()
{
	return this->gameMap;
}
std::vector<StaticObject*> GameMap::getVisibleMap(){
	return this->visibleMap;
}

std::deque<Position> GameMap::moveToMonster(Position pos)
{
	std::deque<Position> q;
	int x = dynamicObjects[0].getPosition().getX();
	int y = dynamicObjects[0].getPosition().getY();
	while (pos.getX() > x) {
		q.push_back(Position(x + 1, y));
		x++;
	}
	while (pos.getX() < x) {
		q.push_back(Position(x - 1, y));
		x--;
	}
	while (pos.getY() > y) {
		q.push_back(Position(x, y + 1));
		y++;
	}
	while (pos.getY() < y) {
		q.push_back(Position(x, y - 1));
		y--;
	}
	return q;
}
std::deque<Position> GameMap::moveToDFS(Position pos, int who)
{
	Position start = this->dynamicObjects[who].getPosition();
	int steps = 20;
	
	std::deque<Position> pathF;
	std::vector<int> prev = bfs(start,pos,steps);
	if (!prev.empty()) {
		pathF = reconstructPath(prev, pos.getX()+pos.getY()*120);
	}
	if (pathF.empty()) {
	std::cout << pos.getX() << "  docelowo  " << pos.getY() << std::endl;
		int x = this->dynamicObjects[who].getPosition().getX();
		int y = this->dynamicObjects[who].getPosition().getY();
		std::cout << x << "  bede w  " << y << std::endl;
		while ((x<119 && !this->gameMap[(y) * 120 + x + 1].getIsSolid() && pos.getX() > x) || (x>0 && !this->gameMap[(y) * 120 + x - 1].getIsSolid() && pos.getX() < x) ||
			(y>0 && !this->gameMap[(y - 1) * 120 + x].getIsSolid() && pos.getY() < y) || (y<119 && !this->gameMap[(y + 1) * 120 + x].getIsSolid() && pos.getY() > y)) {
			if (pos.getX() > x && !this->gameMap[(y) * 120 + x + 1].getIsSolid()) {
				pathF.push_back(Position(x + 1, y));
				x++;
			}
			else if (pos.getX() < x && !this->gameMap[(y) * 120 + x - 1].getIsSolid()) {
				pathF.push_back(Position(x - 1, y));
				x--;
			}
			else if (pos.getY() > y && !this->gameMap[(y + 1) * 120 + x].getIsSolid()) {
				pathF.push_back(Position(x, y + 1));
				y++;
			}
			else if (pos.getY() < y && !this->gameMap[(y - 1) * 120 + x].getIsSolid()) {
				pathF.push_back(Position(x, y - 1));
				y--;
			}
	}
	}
	return pathF;
}
//std::deque<Position> GameMap::dfsHelper(Position start, std::vector<bool>& visited, std::deque<Position>& path, Position target, int stepsLeft)
//{
//
//	if (stepsLeft<=0) {
//		return std::deque<Position>();
//	}
//	std::stack<Position> stack;
//	std::cout << start.getX() << "  <x , y>  " << start.getY() << std::endl;
//	visited[start.getX() + start.getY() * 120] = true;
//	stack.push(start);
//	path.push_back(start);
//	if (start == target) {
//		return path;
//	}
//	std::vector<Position> connections = this->gameMap[start.getX() + start.getY() * 120].canPassTo();
//	for (int i = 0;i < 4;i++) {
//		if (connections[i].getX()!=-1 && !visited[connections[i].getX() + connections[i].getY() * 120]) {
//			stack.push(connections[i]);
//		}
//	}
//	while (!stack.empty()) {
//		Position newStart = stack.top();
//		stack.pop();
//		path = dfsHelper(newStart, visited, path, target, stepsLeft-1);
//	}
//	path.pop_back();
//	visited[start.getX() + start.getY() * 120] = false;
//	return path;
//}
std::vector<int> GameMap::bfs(Position start, Position target, int maxSteps) {
	std::vector<int> distances(14400, INT_MAX);
	std::vector<int> previous(14400, -1);
	std::vector<bool> visited;
	for (int i = 0; i < 120 * 120;i++) {
		if (this->gameMap[i].getIsSolid()) {
			visited.push_back(true);
		}
		else {
			visited.push_back(false);
		}
	}
	std::queue<Position> q;
	distances[start.getY() * 120 + start.getX()] = 0;
	visited[start.getY() * 120 + start.getX()] = true;
	q.push(start);
	while (!q.empty()) {
		Position current = q.front();
		q.pop();
		if (distances[current.getY() * 120 + current.getX()] > maxSteps) {
			break;
		}
		for (Position connection : this->gameMap[current.getY() * 120 + current.getX()].canPassTo()) {
			if (connection.getX()==-1);
			else if (!visited[connection.getY() * 120 + connection.getX()]) {
				visited[connection.getY() * 120 + connection.getX()] = true;
				distances[connection.getY() * 120 + connection.getX()] = distances[current.getY() * 120 + current.getX()];
				previous[connection.getY() * 120 + connection.getX()] = current.getY() * 120 + current.getX();
				q.push(connection);
				if (connection == target) {
					return previous;
				}
			}
		}
	}
	return std::vector<int>();
}
	std::deque<Position> GameMap::reconstructPath(const std::vector<int>&previous, int target) {
		std::deque<Position> path;
		int currentInt = target;
		while (currentInt != -1){
			path.push_front(Position(currentInt % 120, (int)(currentInt / 120)));
			this->gameMap[currentInt].setRectColor(sf::Color(255, 255, 224));
			currentInt = previous[currentInt];
		}
		return path;

}