#include "Vehiculo.h"

Vehiculo::Vehiculo()
{
    _speed = 0.1;
    
    //RANDOM TEXTURE
    srand(time(NULL));
    int ran;
    ran = rand() % 3 + 1;

    switch (ran)
    {
    case 1:
        _texture.loadFromFile("assets/car6_purple.png");
        break;
    case 2:
        _texture.loadFromFile("assets/car6_yellow.png");
        break;
    case 3:
        _texture.loadFromFile("assets/car6_red.png");
        break;
    default:
        break;
    }

    enemy.setTexture(_texture);
}

void Vehiculo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(enemy, states);
}

void Vehiculo::update()
{
    enemy.move(_dir, 0);
    if (enemy.getPosition().x > 700)
    {
        enemy.setPosition(respawn_x, respawn_y);
    }
}

sf::FloatRect Vehiculo::getBounds() const
{
    return enemy.getGlobalBounds();
}

void Vehiculo::setMove(float x)
{
    _dir = x;
}

void Vehiculo::setPos(float x, float y)
{
    enemy.setPosition(x, y);
}

void Vehiculo::setRot(float r)
{
    enemy.setRotation(r);
}

void Vehiculo::setRespawn(float rx, float ry)
{
    respawn_x = rx;
    respawn_y = ry;
}

