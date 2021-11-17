#include "Cuadrante.h"

void Cuadrante::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_cuadrante, states);
}


sf::FloatRect Cuadrante::getBounds() const
{
    return _cuadrante.getGlobalBounds();
}

Cuadrante::Cuadrante()
{
    _texture.loadFromFile("assets/cuadrante.png");
    _cuadrante.setTexture(_texture);
    _cuadrante.setPosition(350, 100);
    //_cuadrante.

}
