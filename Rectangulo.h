#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class Rectangulo: public sf::Drawable, public Collisionable
{
private:
	sf::RectangleShape _rect[6];
	sf::CircleShape _circ;

public:
	Rectangulo();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::FloatRect getBounds() const override; //no funca
	sf::FloatRect getBounds1();
	sf::FloatRect getBounds2();
	sf::FloatRect getBounds3();
	sf::FloatRect getBounds4();
	sf::FloatRect getBounds5(); //circle
	sf::FloatRect getBounds6();
	void setPosRect1(float x, float y);
	void setPosRect2(float x, float y);
	void setPosRect3(float x, float y);
	void setPosRect4(float x, float y);
	void setPosRect5(float x, float y);
	void setPosRect6(float x, float y);
	void setPosCircle(float x, float y);

	void setSizeRect1(float x, float y);
	void setSizeRect2(float x, float y);
	void setSizeRect3(float x, float y);
	void setSizeRect4(float x, float y);
	void setSizeRect5(float x, float y);
	void setSizeRect6(float x, float y);
	void setSizeCircle(float s);
};

