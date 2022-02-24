#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

//HACER QUE CADA NIVEL CREE LOS ENEMIGOS QUE NECESITE Y EDITE TODAS LAS PROPIEDADES, EJ TAMAÑO,POSICION,ETC

class Vehiculo: public sf::Drawable, public Collisionable
{
private:
    sf::Sprite enemy;
    sf::Texture _texture;
    float _speed;
    float _dir;
    float limit;
    float respawn_x;
    float respawn_y;

public:
	Vehiculo();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void update();
    sf::FloatRect getBounds() const override;
    void setMove(float x);
    void setPos(float x, float y);
    void setRot(float r);
    void setRespawn(float rx, float ry);
};

