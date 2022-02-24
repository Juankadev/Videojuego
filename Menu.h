#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Menu: public sf::Drawable
{
	protected:
		sf::RectangleShape _fondo;
		sf::Texture _texture;
		sf::Text _textPlay;
		//sf::Text _textControls;
		sf::Text _textExit;
		sf::Font _font;
		float scale, sumar;
		bool opc1, opc2, opc3;
		sf::SoundBuffer buffer;
		sf::Sound sound;
		int cont;
		//img
		sf::Sprite img_play, img_s;
		sf::Texture img_play_text, img_s_text;
	

	public:
		Menu();
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		int seleccionar_opcion();
		void animationText();
		void setCont(int c) { cont = c; }
};

