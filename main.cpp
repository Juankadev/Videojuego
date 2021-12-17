#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include "Auto.h"
#include "Rectangulo.h"
#include "Cuadrante.h"
#include "Menu.h"
#include <Windows.h>
#include <cstdlib>
#include "FinNivel.h"
#include "NIvel1.h"
#include "Nivel2.h"

using namespace std;

/*
class Enemy
{
private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    float _speed;

public:
    Enemy()
    {
        _speed = 0.1;
        _sprite.setScale(1.1, 1.1);
        _sprite.setPosition(0, 350);
        //RANDOM TEXTURE
        srand(time(NULL));
        int ran;
        ran = rand() % 3 + 1;

        switch (ran)
        {
        case 1:
            _texture.loadFromFile("assets/car6_purple.png");
            break;
        case 2:
            _texture.loadFromFile("assets/car6_yellow.png");
            break;
        case 3:
            _texture.loadFromFile("assets/car6_red.png");
            break;
        }
        _sprite.setTexture(_texture);
    }

    void update()
    {
        _sprite.move(0.5, 0);
        if (_sprite.getPosition().x > 600)
        {
            _sprite.setPosition(0, 350);
        }
    }
};
*/


int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!!");
    sf::View view(sf::FloatRect(600.f, 600.f, 600.f, 600.f));



    //ESTE ENEMIGO DEBE CREARSE EN LA CLASE VEHICULOS
    sf::Sprite enemy2;
    sf::Texture _texture2;
    float _speed2;
    _speed2 = 0.1;
    //enemy.setScale(1.1, 1.1);
    enemy2.setPosition(650, 280);
    enemy2.rotate(-90);
    _texture2.loadFromFile("assets/car6_purple.png");
    enemy2.setTexture(_texture2);




    Menu menu;
    sf::Music music;
    FinNivel win;
    NIvel1 nivel1;
    Nivel2 nivel2;


    bool dibujar = false;
    bool ganaste = false;
    int cambiarnivel = false;
    int numerodenivel = 1;
    bool ejecutado1 = false;
    bool ejecutado2 = false;

    //music
    if (!music.openFromFile("assets/music.wav"))
    {
        cout << "Error al cargar la musica" << endl;
    }

    music.setVolume(10);
    music.setLoop(true);
    music.play();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        //KEYBOARDS

        //cuando apreto enter empieza el juego
        if (menu.seleccionar_opcion()==true) //si apretó enter
        {
            dibujar = true;
            //music.resetBuffer();
        }

        

        //UPDATES
        //car.update();
        menu.animationText();
        nivel1.updates();
        nivel2.updates();
        nivel2.updates2();

        

        enemy2.move(-0.5, 0);
        if (enemy2.getPosition().x < -100)
        {
            enemy2.setPosition(650, 280);
        }

        //colision cuadrante para estacionar
        nivel1.auto_estacionado();
        nivel2.auto_estacionado();

        //colision objetos
        nivel1.colisiones_auto_y_objetos();
        nivel2.colisiones_auto_y_objetos2();
        /*if (numerodenivel == 2)
        {
            if (nivel2.getBoundsAuto().intersects(enemy.getGlobalBounds()))
            {
                nivel2.posicionInicial(550, 500);
            }
        }
        */

        ////////////////
        window.clear();


        //DRAW

        //cuando apreto enter empieza el juego
        if (dibujar == true) 
        {
            switch (numerodenivel)
            {
            case 1:
                window.draw(nivel1);
                break;
            case 2:
                window.draw(nivel2);
                window.draw(enemy2);
                break;
            }
        }
        else
        {
            window.draw(menu);
        }

        //hacer que solo se ejecute una vez
        //SI ESTACIONO BIEN

        if (nivel1.auto_estacionado() == true)
        {
            //para que se repita una vez el codigo de aumentar el nivel
            if (ejecutado1 == false)
            {
                window.draw(win);
                dibujar = false; //me lleva al menu
                cambiarnivel = true;
                ejecutado1 = true;
            }
            //nivel1.~NIvel1();
        }


        if (nivel2.auto_estacionado() == true)
        {
            //para que se repita una vez el codigo de aumentar el nivel
            if (ejecutado2 == false)
            {
                window.draw(win);
                dibujar = false; //me lleva al menu
                cambiarnivel = true;
                ejecutado2 = true;
            }
            //nivel1.~NIvel1();
        }



        ///////////////////////////////
        if (cambiarnivel == true)
        {
            cambiarnivel = false;
            numerodenivel += 1;
            //ejecutado = false;
        }

        if (numerodenivel == 3)
        {
            return 0;
        }


        //
        window.display();
    }

    return 0;
}