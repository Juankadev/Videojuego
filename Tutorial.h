#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Menu.h"

class Tutorial: public Menu
{
private:
	sf::Sprite teclas;
	sf::Texture teclasText;

public:
	Tutorial();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	bool seleccionar_opcion();
};

