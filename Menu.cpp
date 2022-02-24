#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu()
{
	cont = 0;
	//_textPlay.setOrigin(_textPlay.getScale().x / 2, _textPlay.getScale().y / 2);
	_textPlay.setOrigin(88, 12);
	_textExit.setOrigin(88, 12);

	sound.setVolume(50);

	opc1 = false;
	opc2 = false;
	opc3 = false;

	if (!buffer.loadFromFile("assets/soundselect.wav"))
	{
		cout << "No se pudo cargar sound select" << endl;
	}

	sound.setBuffer(buffer);
		
	_texture.loadFromFile("assets/menu.png");
	_fondo.setSize(sf::Vector2f(600, 600));
	_fondo.setTexture(&_texture);

	if (!_font.loadFromFile("assets/Nesatho.ttf"))
	{
		// error...
	}

	scale = 0.0004;
	sumar = true;

	_textPlay.setFont(_font);
	_textPlay.setString("Jugar");
	_textPlay.setCharacterSize(30);
	_textPlay.setFillColor(sf::Color::Yellow);
	_textPlay.setOutlineColor(sf::Color::Black);
	_textPlay.setOutlineThickness(2);
	_textPlay.setPosition(350,380);

	//_textControls.setFont(_font);
	//_textControls.setString("Controles");
	//_textControls.setCharacterSize(25);
	//_textControls.setFillColor(sf::Color::White);
	//_textControls.setOutlineColor(sf::Color::Black);
	//_textControls.setOutlineThickness(3);
	//_textControls.setPosition(220,380);
	
	_textExit.setFont(_font);
	_textExit.setString("Salir");
	_textExit.setCharacterSize(30);
	_textExit.setFillColor(sf::Color::Yellow);
	_textExit.setOutlineColor(sf::Color::Black);
	_textExit.setOutlineThickness(2);
	_textExit.setPosition(350,450);


	//_textPlay.setStyle(sf::Text::Bold);
	//_textControls.setStyle(sf::Text::Bold | sf::Text::Underlined);
	//_textExit.setStyle(sf::Text::Bold | sf::Text::Underlined);


	img_s_text.loadFromFile("assets/key_s.png");
	img_s.setTexture(img_s_text);
	img_s.setPosition(400, 440);
	img_s.setScale(0.07, 0.07);

	img_play_text.loadFromFile("assets/enter.png");
	img_play.setTexture(img_play_text);
	img_play.setPosition(392, 367);
	img_play.setScale(0.022, 0.022);
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_fondo, states);
	target.draw(_textPlay, states);
	//target.draw(_textControls, states);
	target.draw(_textExit, states);
	target.draw(img_s, states);
	target.draw(img_play, states);

}

int Menu::seleccionar_opcion()
{
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && opc1==false)
	{
		_textPlay.setFillColor(sf::Color::Yellow);
		_textControls.setFillColor(sf::Color::White);
		_textExit.setFillColor(sf::Color::White);
		//_textPlay.setCharacterSize(30);
		opc1 == true;
	}*/


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && cont==0)
	{
		sound.play();
		cont = 1;
		return 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		sound.play();
		return 2;
	}

	return 0;
}

//funcion silenciar sonidos??

void Menu::animationText()
{
	
	if (_textPlay.getScale().x <= 1.2 && _textPlay.getScale().y <= 1.2 && sumar==true)
	{
		_textPlay.setScale(_textPlay.getScale().x + scale, _textPlay.getScale().y + scale);	
		img_s.setScale(img_s.getScale().x + scale /10, img_s.getScale().y + scale /10);
		img_play.setScale(img_play.getScale().x + scale / 35, img_play.getScale().y + scale / 35);
	}
	else
	{
		sumar = false;
		_textPlay.setScale(_textPlay.getScale().x - scale, _textPlay.getScale().y - scale);
		img_s.setScale(img_s.getScale().x - scale /10, img_s.getScale().y - scale /10);
		img_play.setScale(img_play.getScale().x - scale / 35, img_play.getScale().y - scale / 35);

		if (_textPlay.getScale().x <= 1 && _textPlay.getScale().y <= 1)
		{
			sumar = true;
		}
	}



	if (_textExit.getScale().x <= 1.2 && _textExit.getScale().y <= 1.2 && sumar == true)
	{
		_textExit.setScale(_textExit.getScale().x + scale, _textExit.getScale().y + scale);
	}
	else
	{
		sumar = false;
		_textExit.setScale(_textExit.getScale().x - scale, _textExit.getScale().y - scale);

		if (_textExit.getScale().x <= 1 && _textExit.getScale().y <= 1)
		{
			sumar = true;
		}
	}

}
