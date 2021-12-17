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

public:
	Vehiculo();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void update();
    sf::FloatRect getBounds() const override;
};

