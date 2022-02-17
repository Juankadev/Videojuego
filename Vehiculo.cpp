#include "Vehiculo.h"

Vehiculo::Vehiculo()
{
    _speed = 0.1;
    enemy.rotate(90);
    enemy.setPosition(20, 350);
    _texture.loadFromFile("assets/car6_yellow.png");
    enemy.setTexture(_texture);
}

void Vehiculo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(enemy, states);
}

void Vehiculo::update()
{
    enemy.move(0.8, 0);
    if (enemy.getPosition().x > 700)
    {
        enemy.setPosition(20, 350);
    }
}

sf::FloatRect Vehiculo::getBounds() const
{
    return enemy.getGlobalBounds();
}
