#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Collisionable.h"

class Auto : public sf::Drawable, public Collisionable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::View view1;
	sf::SoundBuffer sound_driving_buffer;
	sf::Sound sound_driving;
	int play;

	/*float _velocityX;
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
	float _speed;*/
	float x, y;
	float speed, angle, maxSpeed, acc, dec, turnSpeed;

public:
	Auto();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::FloatRect getBounds() const override;
	sf::Vector2f getPosition();
	//sf::Vector2f getView1();
	//sf::Sound getSoundChoque();
	//void posicionInicial(float x, float y);
	void setPos(float x, float y);
	void setRot(float r);
	void setAngle(float a);
	void respawn(float x1, float y1, float a);
};

