#include "Menu.h"
#include <iostream>
using namespace std;

Menu::~Menu()
{
	//devuelvo memoria
	delete _datos; 
}

Menu::Menu()
{
	//ARCHIVO
	//LEER DE DISCO
	/*f = fopen("archivos/estadisticas.txt", "rb");
	if (f == NULL) { cout << "Error de apertura" << endl; }
	fread(&choques, sizeof(int), 1, f);
	fclose(f);*/
	buscarmax();
	//strChoques = to_string(choques);
	elementos = cantElementos();
	_datos = new sf::Text[elementos];

	f = fopen("archivos/estadisticas.txt", "rb");
	if (f == NULL) { cout << "Error de apertura" << endl; }

	int aux;

	for (int i = 0; i < elementos; i++)
	{
		fseek(f, sizeof(int) * i, 0);
		fread(&aux, sizeof(int), 1, f);
		_datos[i].setString(to_string(aux));
	}

	fclose(f);


	cont = 0;
	//_textPlay.setOrigin(_textPlay.getScale().x / 2, _textPlay.getScale().y / 2);
	_textPlay.setOrigin(88, 12);
	_textExit.setOrigin(88, 12);
	_text_cant_choques.setOrigin(88, 12);

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

	_text_cant_choques.setFont(_font);
	_text_cant_choques.setString("Choques maximos: "); //string choques
	_text_cant_choques.setCharacterSize(20);
	_text_cant_choques.setFillColor(sf::Color::White);
	_text_cant_choques.setOutlineColor(sf::Color::Black);
	_text_cant_choques.setOutlineThickness(2);
	_text_cant_choques.setPosition(280, 550);

	_text_num_choques.setFont(_font);
	_text_num_choques.setString(strChoques); //string choques
	_text_num_choques.setCharacterSize(30);
	_text_num_choques.setFillColor(sf::Color::Magenta);
	_text_num_choques.setOutlineColor(sf::Color::Black);
	_text_num_choques.setOutlineThickness(2);
	_text_num_choques.setPosition(430, 530);


	_estadisticas.setFont(_font);
	_estadisticas.setString("Choques por partida");
	_estadisticas.setCharacterSize(20);
	_estadisticas.setFillColor(sf::Color::Yellow);
	_estadisticas.setOutlineColor(sf::Color::Black);
	_estadisticas.setOutlineThickness(2);
	_estadisticas.setPosition(10, 5);

	_fondo_estadistica.setFillColor(sf::Color(136, 186, 210, 170));
	_fondo_estadistica.setPosition(10, 30);
	_fondo_estadistica.setSize(sf::Vector2f(50, 570));


	//valores _datos
	for (int i = 0; i < elementos; i++)
	{
		_datos[i].setFont(_font);
		_datos[i].setCharacterSize(20);
		_datos[i].setFillColor(sf::Color::White);
		_datos[i].setOutlineColor(sf::Color::Black);
		_datos[i].setOutlineThickness(2);
		_datos[i].setPosition(20, (i+1)*26);
	}


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
	target.draw(img_play, states);
	target.draw(_textExit, states);
	target.draw(img_s, states);
	target.draw(_text_cant_choques, states);
	target.draw(_text_num_choques, states);
	target.draw(_fondo_estadistica, states);
	target.draw(_estadisticas, states);
	for (int i = 0; i < elementos; i++)
	{
		target.draw(_datos[i], states);
	}
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

	//Actualizo maximos
	_text_num_choques.setString(strChoques); //string choques
	
}

int Menu::getChoques()
{
	return choques;
}


void Menu::grabarEnDisco(int c)
{
	//guardar en disco
	f = fopen("archivos/estadisticas.txt", "ab");
	if (f == NULL) { cout << "Error de apertura" << endl; }
	fwrite(&c, sizeof(int), 1, f);
	fclose(f);

	//agrando memoria dinamica de datos de choques

	//seteo en el menu el maximo valor
	buscarmax();
	//actualizar rank
	//delete _datos;
	todosLosChoques();
}

void Menu::buscarmax()
{
	//leer y buscar mayor
	f = fopen("archivos/estadisticas.txt", "rb");
	if (f == NULL) { cout << "Error de apertura" << endl; }

	int max = 0, aux;

	while (fread(&aux, sizeof(int), 1, f))
	{
		if (aux > max)
		{
			max = aux;
			//cout << "COMPARO" << endl;
		}
	}
	fclose(f);

	//seteo en el menu el valor
	strChoques = to_string(max);
}

int Menu::cantElementos()
{
	int bytes;

	f = fopen("archivos/estadisticas.txt", "rb");
	if (f == NULL) { cout << "Error de apertura" << endl; }

	fseek(f, 0, SEEK_END);
	bytes = ftell(f) / sizeof(int);

	fclose(f);
	return bytes;
}

void Menu::todosLosChoques() //VER PROBLEMA DE MEMORIA DINAMICA
{
	f = fopen("archivos/estadisticas.txt", "rb");
	if (f == NULL) { cout << "Error de apertura" << endl; }

	int aux;
	//HAY QUE AGRANDAR LA MEMORIA DINAMICA LUEGO DE GUARDAR PARTIDA CON EL NUEVO DATO
	elementos = cantElementos(); //PROBLEMA PARA MOSTRAR EN MENU
	_datos = new sf::Text[elementos];//PROBLEMA PARA MOSTRAR EN MENU

	for (int i = 0; i < elementos; i++)
	{
		fseek(f, sizeof(int) * i, 0);
		fread(&aux, sizeof(int), 1, f);
		_datos[i].setString(to_string(aux));
	}

	fclose(f);
}


