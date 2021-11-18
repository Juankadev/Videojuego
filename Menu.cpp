#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu()
{
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

	scale = 0.0005;
	sumar = true;

	_textPlay.setFont(_font);
	_textPlay.setString("Jugar");
	_textPlay.setCharacterSize(30);
	_textPlay.setFillColor(sf::Color::Yellow);
	_textPlay.setOutlineColor(sf::Color::Black);
	_textPlay.setOutlineThickness(2);
	_textPlay.setPosition(230,380);

	//_textControls.setFont(_font);
	//_textControls.setString("Controles");
	//_textControls.setCharacterSize(25);
	//_textControls.setFillColor(sf::Color::White);
	//_textControls.setOutlineColor(sf::Color::Black);
	//_textControls.setOutlineThickness(3);
	//_textControls.setPosition(220,380);
	//
	//_textExit.setFont(_font);
	//_textExit.setString("Salir");
	//_textExit.setCharacterSize(25);
	//_textExit.setFillColor(sf::Color::White);
	//_textExit.setOutlineColor(sf::Color::Black);
	//_textExit.setOutlineThickness(3);
	//_textExit.setPosition(420,380);


	//_textPlay.setStyle(sf::Text::Bold);
	//_textControls.setStyle(sf::Text::Bold | sf::Text::Underlined);
	//_textExit.setStyle(sf::Text::Bold | sf::Text::Underlined);

}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_fondo, states);
	target.draw(_textPlay, states);
	//target.draw(_textControls, states);
	//target.draw(_textExit, states);

}

bool Menu::seleccionar_opcion()
{
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && opc1==false)
	{
		_textPlay.setFillColor(sf::Color::Yellow);
		_textControls.setFillColor(sf::Color::White);
		_textExit.setFillColor(sf::Color::White);
		//_textPlay.setCharacterSize(30);
		opc1 == true;
	}*/
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		sound.play();
		return true;
	}

	return false;
}

void Menu::animationText()
{
	
	if (_textPlay.getScale().x <= 1.2 && _textPlay.getScale().y <= 1.2 && sumar==true)
	{
		_textPlay.setScale(_textPlay.getScale().x + scale, _textPlay.getScale().y + scale);
	}
	else
	{
		sumar = false;
		_textPlay.setScale(_textPlay.getScale().x - scale, _textPlay.getScale().y - scale);

		if (_textPlay.getScale().x <= 1 && _textPlay.getScale().y <= 1)
		{
			sumar = true;
		}
	}

}
