#include "Tutorial.h"

Tutorial::Tutorial()
{
	_texture.loadFromFile("assets/tutorial.png");
	_textPlay.setString("Entendido - 'X' ");
	_textPlay.setPosition(300, 380);
	_textPlay.setOrigin(127, 12);
	//_fondo.setSize(sf::Vector2f(600, 600));
	//_fondo.setTexture(&_texture);
}


/*void Tutorial::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Menu::draw(target,states);
}*/


bool Tutorial::seleccionar_opcion()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		sound.play();
		return true;
	}

	return false;
}
