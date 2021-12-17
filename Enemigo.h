#pragma once
#include "Collisionable.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Enemigo: public Collisionable, sf::Drawable
{
	private:
		sf::Sprite _sprite;
		sf::Texture _texture;
		float _speed;

	public:
		Enemigo();
		void update();
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		//sf::FloatRect getBounds() const override;
};

