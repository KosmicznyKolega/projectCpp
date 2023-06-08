#include "WinningSpace.h"

WinningSpace::WinningSpace(Position position) : StaticObject(position) {
    //this->texture.loadFromFile("wygrana.png");
    //this->sprite.setTexture(this->texture);
    this->win = true;
    this->rect.setFillColor(sf::Color::Yellow);
}
WinningSpace::WinningSpace(const WinningSpace& win) : StaticObject(win.getPosition()) {
    //this->texture.loadFromFile("wygrana.png");
    //this->sprite.setTexture(this->texture);
    this->win = true;
    this->rect.setFillColor(sf::Color::Yellow);
}
WinningSpace::WinningSpace() : StaticObject()
{
    this->win = true;
    this->rect.setFillColor(sf::Color::Yellow);
}
WinningSpace& WinningSpace::operator=(const WinningSpace& ws)
{
    if (this != &ws) {
        this->connections = ws.canPassTo();
        this->rect = ws.getSprite();
        this->isSolid = ws.getIsSolid();
        this->position = ws.getPosition();
        this->win = true;
    }
    return *this;
}
StaticObject& WinningSpace::toStatOb() {
    return static_cast<StaticObject&>(*this);
}