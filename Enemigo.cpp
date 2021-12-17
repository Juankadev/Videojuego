#include "Enemigo.h"

Enemigo::Enemigo()
{
    _speed = 0.1;
    _sprite.setScale(1.1, 1.1);
    _sprite.setPosition(0, 350);


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


    _sprite.setTexture(_texture);
}

void Enemigo::update()
{
    _sprite.move(0.5, 0);
    if (_sprite.getPosition().x > 600)
    {
        _sprite.setPosition(0, 350);
    }
}


void Enemigo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}