#include "GameHandler.h"
#include "MapProvider.h"
#include <deque>
#include <random>
#include "Position.h"
#include <SFML/Graphics.hpp>
#include <iostream>
//================================================//
GameHandler::GameHandler() {}
GameHandler::~GameHandler() {}
void GameHandler::run() {
	sf::RenderWindow window(sf::VideoMode(760, 760), "gra123");
	MapProvider mapProvider;
	GameMap gameMap;
	gameMap.initMap(mapProvider.getMapOfStaticObjects());
	while (window.isOpen()) {
		sf::Clock clock;
		sf::Event event;
		while (window.pollEvent(event)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
				gameMap.getDynamicObjects()[1].setSpeedControl(2);
			}
			else {
				gameMap.getDynamicObjects()[1].setSpeedControl(5);
			}
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::MouseButtonPressed) {
				//std::cout << gameMap.getVisibleMap()[(int)(event.mouseButton.y / 50) + (int)(event.mouseButton.x/ 50) * 15]->getPosition().getX() << "  przeslalem  " << gameMap.getVisibleMap()[(int)(event.mouseButton.y / 50) + (int)(event.mouseButton.x / 50) * 15]->getPosition().getY() << std::endl;
				int  y = gameMap.getVisibleMap()[(int)(event.mouseButton.x / 50) + (int)(event.mouseButton.y / 50) * 15]->getPosition().getX();
				int  x = gameMap.getVisibleMap()[(int)(event.mouseButton.x / 50) + (int)(event.mouseButton.y / 50) * 15]->getPosition().getY();
				//std::cout << x << "<- x   y ->" << y <<std::endl;
				if (!gameMap.getDynamicObjects()[1].getMoveQueue().empty()) {
					std::deque<Position> deq = gameMap.getDynamicObjects()[1].getMoveQueue();
					while (!deq.empty()) {
						gameMap.getGameMap()[deq.front().getY() * 120 + deq.front().getX()].setRectColor(sf::Color::White);
						deq.pop_front();
					}
				}
				gameMap.getDynamicObjects()[1].setMoveQueue(gameMap.moveToDFS(Position(x,y), 1));
			}
		}
		gameMap.changeVisibleMap();
		//players move
		if (gameMap.getDynamicObjects()[1].hasDestination()) {
			Position check = gameMap.getDynamicObjects()[1].getPosition();
			gameMap.getDynamicObjects()[1].moveNext();
			if (!(check == gameMap.getDynamicObjects()[1].getPosition())) {
				gameMap.getGameMap()[check.getX() + check.getY() * 120].setRectColor(sf::Color::White);
			}
			std::cout << gameMap.getDynamicObjects()[1].getPosition().getX() << "  przyszedlem do  " << gameMap.getDynamicObjects()[1].getPosition().getY() << std::endl;

		}
		if (gameMap.getDynamicObjects()[0].getPosition() == gameMap.getDynamicObjects()[1].getPosition()) {
			std::cout << "przegrales" << std::endl;
			window.close();

		}
		else if (gameMap.getGameMap()[gameMap.getDynamicObjects()[1].getPosition().getX() + (gameMap.getDynamicObjects()[1].getPosition().getY() * 120)].didWin()) {
			std::cout << "wygrales" <<std::endl;
			window.close();

		}
		//monster move
		if (gameMap.getDynamicObjects()[0].hasDestination()) {
			gameMap.getDynamicObjects()[0].moveNext();
			if (gameMap.getGameMap()[gameMap.getDynamicObjects()[0].getPosition().getX() + gameMap.getDynamicObjects()[0].getPosition().getY() * 120].getIsSolid()) {
				gameMap.destroyAt(gameMap.getDynamicObjects()[0].getPosition());
			}
		}
		else if (gameMap.getDynamicObjects()[0].hearsPlayer(gameMap.getDynamicObjects()[1].getPosition())) {
			std::cout << "ide po ciebie!" << std::endl;
			gameMap.getDynamicObjects()[0].setMoveQueue(gameMap.moveToMonster(gameMap.getDynamicObjects()[1].getPosition()));
		}
		else {
			gameMap.getDynamicObjects()[0].moveRand();
		}
		if (gameMap.getDynamicObjects()[0].getPosition() == gameMap.getDynamicObjects()[1].getPosition()) {
			std::cout << "przegrales" << std::endl;
			window.close();
		}
		window.clear();
		for (int i = 0;i < 15 * 15;i++) {
			window.draw(gameMap.getVisibleMap()[i]->getSprite());
		}
		window.draw(gameMap.getDynamicObjects()[0].getSprite());
		window.draw(gameMap.getDynamicObjects()[1].getSprite());
		window.display();
		while (clock.getElapsedTime().asMilliseconds() < 40) {

		}
	}
}
