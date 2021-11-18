#include "FinNivel.h"

FinNivel::FinNivel()
{
	if (!_font.loadFromFile("assets/Nesatho.ttf"))
	{
		// error...
	}

	_win.setFont(_font);
	_win.setString("¡Eres un gran \n conductor!");
	_win.setCharacterSize(40);
	_win.setFillColor(sf::Color::White);
	_win.setOutlineColor(sf::Color::Black);
	_win.setOutlineThickness(3);
	_win.setPosition(150, 250);
}

void FinNivel::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_win,states);
}
