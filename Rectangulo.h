#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class Rectangulo: public sf::Drawable, public Collisionable
{
private:
	sf::Sprite _sprite;

public:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::FloatRect getBounds() const override;
};

