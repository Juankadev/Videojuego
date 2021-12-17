#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class Cuadrante: public sf::Drawable, public Collisionable
{
	private:
		sf::Sprite _cuadrante;
		sf::Texture _texture;


	public:
		Cuadrante();
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		//void draw(sf::RenderWindow& window);
		sf::FloatRect getBounds() const override;
		void setPos(float x, float y);
		void setRot(float r);
		
};

