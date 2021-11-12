#include "Auto.h"
#include <iostream>
using namespace std;

Auto::Auto()
{
    _velocityX = 0;
    _velocityY = 0;
    _maxVelocity = 0.7;
    //view1.setSize(200.f, 200.f);

    //RANDOM TEXTURE
    srand(time(NULL));
    int ran;
    ran = rand() % 3 + 1;

    switch (ran)
    {
    case 1:
        _texture.loadFromFile("assets/car3_blue.png");
        break;
    case 2:
        _texture.loadFromFile("assets/car3_green.png");
        break;
    case 3:
        _texture.loadFromFile("assets/car3_orange.png");
        break;
    default:
        break;
    }


    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    _sprite.setPosition(500, 500);
}



void Auto::update()
{
    //MOVIMIENTO

    bool up=0, down=0, left=0, right=0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))      up = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))    down = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))    left = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))   right = 1;

    //
    if (up)
    {

        //if (_sprite.getRotation() > 90 && _sprite.getRotation() <= 270)
        //{
            if (_velocityY > -_maxVelocity)
            {
                _velocityY -= 0.001f;
            }
        //}

        /*else
        { 
            if (_velocityY < _maxVelocity)
            {
                _velocityY -= 0.001f;
            }
        }*/
        
        //cout << _velocityY << endl;
        
        if (right)
        {
            _velocityX += 0.001f;
            _sprite.setRotation(_sprite.getRotation() + 0.2);
        }

        
        if (left)
        {
            _velocityX -= 0.001f;
            _sprite.setRotation(_sprite.getRotation() - 0.2);  
        }

        
    }




    if (down)
    {
        //if (_sprite.getRotation() > 90 && _sprite.getRotation() <= 270)
        //{
            if (_velocityY < _maxVelocity)
            {
                _velocityY += 0.001f;
            }
        //}

        /*else
        {
            if (_velocityY < _maxVelocity)
            {
                _velocityY -= 0.001f;
            }
        }

        cout << _velocityY << endl;

        if (right)
        {
            _velocityX += 0.001f;
            _sprite.setRotation(_sprite.getRotation() + 0.2);
        }


        if (left)
        {
            _velocityX -= 0.001f;
            _sprite.setRotation(_sprite.getRotation() - 0.2);
        }

        */
    }



    //FRICCION UP
    /*
    if (!up)
    {
        if (_velocityY < 0)
        {
            _velocityY += 0.001f;

            if (_velocityX > 0)
            {
                _velocityX -= 0.001f;
            }
            if (_velocityX < 0)
            {
                _velocityX += 0.001f;
            }
            

            if (right)
            {
                _sprite.setRotation(_sprite.getRotation() + 0.2);
            }

            if (left)
            {
                _sprite.setRotation(_sprite.getRotation() - 0.2);
            }
        }

        //cout << _velocityY << endl;
    }
    */









    

    /*
    if (left && !up)
    {
        _sprite.setRotation(_sprite.getRotation() - 0.1);
    }*/



    //
    
    /*
    if (up && left)
    {
        _velocityX -= 0.001f;
        _velocityY += 0.001f;
        _sprite.setRotation(_sprite.getRotation() - 0.1);
    }
    
    if (down && right)
    {
        _velocityX += 0.001f;
        _velocityY -= 0.001f;
        _sprite.setRotation(_sprite.getRotation() - 0.1);
    }

    if (down && left)
    {
        _velocityX -= 0.001f;
        _velocityY -= 0.001f;
        _sprite.setRotation(_sprite.getRotation() + 0.1);
    }

    */


    

    /*
    if (!down)
    {
        if (_velocityY > 0)
        {
            _velocityY -= 0.001f;
        }
    }

    if (!right)
    {
        if (_velocityX > 0)
        {
            _velocityX -= 0.001f;
        }
    }

    if (!left)
    {
        if (_velocityX < 0)
        {
            _velocityX += 0.001f;
        }
    }
    */


    _sprite.move(_velocityX, _velocityY);

    //_sprite.getGlobalBou
    

    //LIMITES
    if(_sprite.getPosition().x  - _sprite.getGlobalBounds().height / 2 < 0)
    {
        _sprite.setPosition(_sprite.getGlobalBounds().height / 2, _sprite.getPosition().y);
        view1.move(10.f, 10.f);
    }

    if (_sprite.getPosition().y - _sprite.getGlobalBounds().height / 2 < 0)
    {
        _sprite.setPosition(_sprite.getPosition().x, _sprite.getGlobalBounds().height/2);
    }

    if (_sprite.getPosition().x + _sprite.getGlobalBounds().height / 2 > 600)
    {
        _sprite.setPosition(600 - _sprite.getGlobalBounds().height / 2, _sprite.getPosition().y);
    }

    if (_sprite.getPosition().y + _sprite.getGlobalBounds().height / 2 > 600)
    {
        _sprite.setPosition(_sprite.getPosition().x, 600 - _sprite.getGlobalBounds().height / 2);
    }
}

void Auto::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

sf::FloatRect Auto::getBounds() const
{
    return _sprite.getGlobalBounds();
}

sf::Vector2f Auto::getPosition()
{
    return sf::Vector2f(_sprite.getPosition().x, _sprite.getPosition().y);
}

sf::Vector2f Auto::getView1()
{
    return sf::Vector2f(view1.getSize());
}