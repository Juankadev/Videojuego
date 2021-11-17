#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Menu: public sf::Drawable
{
	private:
		sf::RectangleShape _fondo;
		sf::Texture _texture;
		sf::Text _textPlay;
		sf::Text _textControls;
		sf::Text _textExit;
		sf::Font _font;
		bool opc1, opc2, opc3;
		sf::SoundBuffer buffer;
		sf::Sound sound;
	

	public:
		Menu();
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		bool seleccionar_opcion();
};

