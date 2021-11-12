#include "Rectangulo.h"

void Rectangulo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

sf::FloatRect Rectangulo::getBounds() const
{
    return _sprite.getGlobalBounds();
}