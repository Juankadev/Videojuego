#include "Cuadrante.h"

void Cuadrante::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_cuadrante, states);
}


sf::FloatRect Cuadrante::getBounds() const
{
    return _cuadrante.getGlobalBounds();
}

void Cuadrante::setPos(float x, float y)
{
    _cuadrante.setPosition(x, y);
}

void Cuadrante::setRot(float r)
{
    _cuadrante.setRotation(r);
}

Cuadrante::Cuadrante()
{
    _texture.loadFromFile("assets/cuadrante.png");
    _cuadrante.setTexture(_texture);
    _cuadrante.setPosition(172, 475);
    _cuadrante.setScale({0.42,0.59});
    _cuadrante.setColor(sf::Color(255, 255, 255,100));
    //_cuadrante.

}
