#include "Tutorial.h"

Tutorial::Tutorial()
{
	_texture.loadFromFile("assets/tutorial.png");
	//_textPlay.setString("Entendido");
	_textPlay.setPosition(350, 500);
	//_textPlay.setOrigin(127, 12);
	_textExit.setPosition(350, 550);

	img_play.setPosition(392, 480);
	img_s.setPosition(400, 540);
	
	
	teclasText.loadFromFile("assets/keys.png");
	teclas.setTexture(teclasText);
	teclas.setPosition(240, 360);
	teclas.setScale(0.6,0.6);
	//_fondo.setSize(sf::Vector2f(600, 600));
	//_fondo.setTexture(&_texture);
}


void Tutorial::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Menu::draw(target,states);
	target.draw(teclas, states);
}


bool Tutorial::seleccionar_opcion()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && cont==0)
	{
		sound.play();
		cont = 1;
		return true;
	}

	return false;
}
