#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
class Menu: public sf::Drawable
{
	protected:
		sf::RectangleShape _fondo;
		sf::Texture _texture;
		sf::Text _textPlay;
		sf::Text _text_cant_choques;
		sf::Text _text_num_choques;
		sf::Text _textExit;
		sf::Text _estadisticas;
		sf::RectangleShape _fondo_estadistica;
		sf::Font _font;
		float scale, sumar;
		bool opc1, opc2, opc3;
		sf::SoundBuffer buffer;
		sf::Sound sound;
		int cont;
		//img
		sf::Sprite img_play, img_s;
		sf::Texture img_play_text, img_s_text;
	
		//Archivo
		FILE* f;
		int choques;
		std::string strChoques;
		sf::Text * _datos;
		int elementos;
		//std::string top10choques[10];
		//char string1[20];
		//char string2[20];

	public:
		Menu();
		~Menu();
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		int seleccionar_opcion();
		void animationText();
		void setCont(int c) { cont = c; }
		void grabarEnDisco(int c);
		int getChoques();
		void buscarmax();
		int cantElementos();
		void todosLosChoques();
};

