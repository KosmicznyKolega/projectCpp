#include "StaticObject.h"
StaticObject::StaticObject(Position position) : position(position), isSolid(false), connections(std::vector<Position>()),rect(sf::RectangleShape(sf::Vector2f(50,50))),win(false){
    //this->texture.loadFromFile("podloga.png");
    //this->sprite.setTexture(this->texture);
    this->rect.setFillColor(sf::Color::White);

}
StaticObject& StaticObject::operator=(const StaticObject& statObj)
{
    if (this != &statObj) {
        this->connections = statObj.canPassTo();
        this->rect = statObj.getSprite();
        this->isSolid = statObj.getIsSolid();
        this->position = statObj.getPosition();
        this->win = statObj.didWin();
    }
    return *this;
}
StaticObject::StaticObject() :position(Position()), isSolid(false), connections(std::vector<Position>()), rect(sf::RectangleShape(sf::Vector2f(50, 50))),win(false) {
    /*this->texture.loadFromFile("podloga.png");
    this->sprite.setTexture(this->texture);*/
    this->rect.setFillColor(sf::Color::White);

}
StaticObject::StaticObject(const StaticObject& statObj) {
    this->connections = statObj.canPassTo();
    this->rect = statObj.getSprite();
    this->isSolid = statObj.getIsSolid();
    this->position = statObj.getPosition();
    this->win = statObj.didWin();
}
StaticObject::~StaticObject(){}
void StaticObject::setRectSize()
{
    this->rect.setSize(sf::Vector2f(50, 50));
}
Position StaticObject::getPosition() const{
    return this->position;
}
sf::RectangleShape StaticObject::getSprite() const
{
    return this->rect;
}
bool StaticObject::didWin() const{
    return this->win;
}
bool StaticObject::getIsSolid() const{
    return isSolid;
}
std::vector<Position> StaticObject::canPassTo() const{
    return connections;
}
void StaticObject::setConnections(std::vector<Position> connections){
    this->connections = std::vector<Position>(connections);
}
void StaticObject::setSpritePos(int x, int y) {
    this->rect.setPosition(x, y);
}
void StaticObject::destroySelf() {
    this->isSolid = false;
    this->rect.setFillColor(sf::Color::White);
}
void StaticObject::setRectColor(sf::Color color) {
    this->rect.setFillColor(color);
}