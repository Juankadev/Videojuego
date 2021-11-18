#pragma once
#include <SFML/Graphics.hpp>

class FinNivel: public sf::Drawable
{
private:
	sf::Text _win;
	sf::Font _font;

public:
	FinNivel();
	//void animationFinNivel();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	//bool seleccionar_opcion();
};

