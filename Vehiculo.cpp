#include "Vehiculo.h"

Vehiculo::Vehiculo()
{
    _speed = 0.1;
    //enemy.setScale(1.1, 1.1);
    enemy.setPosition(100, 350);
    enemy.rotate(90);
    _texture.loadFromFile("assets/car6_purple.png");
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
        enemy.setPosition(0, 350);
    }
}

sf::FloatRect Vehiculo::getBounds() const
{
    return enemy.getGlobalBounds();
}
