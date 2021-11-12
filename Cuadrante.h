#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class Cuadrante: public sf::Drawable, public Collisionable
{
	private:
		sf::RectangleShape cuadrante;
		sf::Sprite _cuadrante;
		sf::Texture _texture;


	public:
		Cuadrante();
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void draw(sf::RenderWindow& window);
		sf::FloatRect getBounds() const override;
};

