#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class Rectangulo: public sf::Drawable, public Collisionable
{
private:
	sf::RectangleShape _rect[5];
	sf::CircleShape _circ;

public:
	Rectangulo();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::FloatRect getBounds() const override;
	sf::FloatRect getBounds1();
	sf::FloatRect getBounds2();
	sf::FloatRect getBounds3();
	sf::FloatRect getBounds4();
	sf::FloatRect getBounds5(); //circle
};

