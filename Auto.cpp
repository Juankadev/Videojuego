#include "Auto.h"
#include <iostream>
#include <cmath>
using namespace std;

Auto::Auto()
{
    //_velocityX = 0;
    //_velocityY = 0;
    //_speed = 0.05;
    //_maxVelocity = 0.1;
    //_angle = 0.01;
    //_sprite.setScale(1.1, 1.1);

    //view1.setSize(200.f, 200.f);
    //_sprite.setRotation(90);

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

    _sprite.setOrigin(38,23);
    _sprite.setTexture(_texture);
    //_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);

    /*if(!motorfx.openFromFile("assets/carmotor.ogg"))
    {
        cout << "Error al cargar sonido de auto" << endl;
    }*/
    //motorfx.setVolume(100);
    //contarrepro = 0;
    //reproducir = true;

    /*if (!bufferchoque.loadFromFile("assets/carmotor.ogg")) {
        cout << "Error sound choque" << endl;
    }
    choque.setBuffer(bufferchoque);*/
    
    x = 100;
    y = 100;
    speed = 0;
    //angle = 1.6;
    maxSpeed = 0.75;
    acc = 0.006;
    dec = 0.006;
    turnSpeed = 0.0025;
}

void Auto::update()
{
    //MOVIMIENTO
    //_velocityX = 0.1;
   // _velocityY = 0.1;

    //_posY = 0;
    //_posX = 0;


    bool Up=0, Down=0, Left=0, Right=0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))      Up = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))    Down = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))    Left = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))   Right = 1;


    //car movement
    if (Up && speed < maxSpeed)
        if (speed < 0)  speed += dec;
        else  speed += acc;

    if (Down && speed > -maxSpeed)
        if (speed > 0) speed -= dec;
        else  speed -= acc;

    if (!Up && !Down)
        if (speed - dec > 0) speed -= dec;
        else if (speed + dec < 0) speed += dec;
        else speed = 0;

    if (Right && speed != 0)  angle += turnSpeed * speed / maxSpeed;
    if (Left && speed != 0)   angle -= turnSpeed * speed / maxSpeed;


    x += sin(angle) * speed;
    y -= cos(angle) * speed;

    _sprite.setPosition(x, y);
    _sprite.setRotation(angle * 180 / 3.141592);

    //
    /*if (up)
    {
        if (reproducir == true && contarrepro==0)
        {
            motorfx.play();
            contarrepro = 1;
        }
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
        }
        
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

    else
    {
        _velocityY = 0;
        _velocityX = 0;
        //reproducir = false;
        //contarrepro = 0;
        //motorfx.stop();
    }

    

    /*if (reproducir == true)
    {
        motorfx.play();
    }*/

    /*
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

        
    }
    */

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

    //float direccion = _sprite.getRotation();
    //velocity
    /*if (up)
    {
        _posY = -_speed;
        if (right)
        {
            _posY = 0;
            _posX = _speed;
        }
        if (left)
        {
            _posY = +_speed;
            _posX = -_speed;
        }

    }
    //if (down) _speed;
    //if (left) if(up || down) _velocityX = -0.3;
    //if (right) _velocityX = 0.3;

   //_posX += sin(_angle);
   //_posY -= cos(_angle);
   */
   //rotation
   //if (_velocityY != 0 && _velocityX !=0  && left) _sprite.setRotation(_sprite.getRotation() - 0.1);;
   //if (_velocityY != 0 && _velocityX != 0 && right) _sprite.setRotation(_sprite.getRotation() + 0.1);;

   //if (up) _posY = -1;
   //if (down) _posY = 1;
   //if (left) _posX = -1;
   //if (right) _posX = 1;

   // _sprite.move(_posX, _posY);
    

    //LIMITES
    if(_sprite.getPosition().x  - _sprite.getGlobalBounds().height / 2 < 0)
    {
        _sprite.setPosition(_sprite.getGlobalBounds().height / 2, _sprite.getPosition().y);
        //view1.move(10.f, 10.f);
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

/*sf::Sound Auto::getSoundChoque()
{
    return choque;
}*/

/*void Auto::posicionInicial(float x, float y)
{
    _sprite.setPosition(x, y);
}*/

void Auto::setPos(float x, float y)
{
    _sprite.setPosition(x, y);
}

void Auto::respawn(float x1, float y1, float a)
{
    x = x1;
    y = y1;
    speed = 0;
    angle = a;
}

void Auto::setRot(float r)
{
    _sprite.setRotation(r);
}

void Auto::setAngle(float a)
{
    angle = a;
}


/*sf::Vector2f Auto::getView1()
{
    return sf::Vector2f(view1.getSize());
}*/

