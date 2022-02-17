#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Menu.h"

class Tutorial: public Menu
{

public:
	Tutorial();
	//void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	bool seleccionar_opcion();
};

