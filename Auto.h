#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Collisionable.h"

class Auto: public sf::Drawable, public Collisionable
{
	private:
		sf::Sprite _sprite;
		sf::Texture _texture;
		float _velocityX;
		float _velocityY;
		float _angle;
		float _maxVelocity;
		sf::View view1;
		sf::Music motorfx;
		sf::Sound choque;
		sf::SoundBuffer bufferchoque;
		bool reproducir;
		int contarrepro;
		float _posY;
		float _posX;
		float _speed;

	public:
		Auto();
		void update();
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		sf::FloatRect getBounds() const override;
		sf::Vector2f getPosition();
		//sf::Vector2f getView1();
		sf::Sound getSoundChoque();
};

