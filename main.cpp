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

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!!");
    sf::View view(sf::FloatRect(600.f, 600.f, 600.f, 600.f));

    Auto car;
    Rectangulo rect;
    Cuadrante cuadrante;
    Menu menu;
    FinNivel win;

    bool dibujar = false;
    bool ganaste = false;
    
    sf::RectangleShape fondo(sf::Vector2f(600, 600));
    sf::Texture texturefondo;
    texturefondo.loadFromFile("assets/fondo2.png");
    fondo.setTexture(&texturefondo);
    
    sf::Music music;
    if (!music.openFromFile("assets/music.wav"))
    { cout << "Error al cargar la musica" << endl; }

    music.setVolume(30);
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

        
        //keyboards
        if (menu.seleccionar_opcion()==true) //si apretó enter
        {
            dibujar = true;
            //music.resetBuffer();
        }

        

        //updates
        car.update();   

        //collision
        if (cuadrante.getBounds().top < car.getBounds().top) //CALCULOS PARA SABER SI EL AUTO ENTRO AL CUADRANTE
        {
            if (cuadrante.getBounds().left < car.getBounds().left)
            {
                if (cuadrante.getBounds().left + cuadrante.getBounds().width > car.getBounds().left + car.getBounds().width)
                {
                    if (cuadrante.getBounds().top + cuadrante.getBounds().height > car.getBounds().top + car.getBounds().height)
                    {
                        //dibujar = false; //para dibujar el menu
                        ganaste = true;
                    }
                }
            }      
        }
        
        //
        window.clear();


        //DRAW
        //window.setView(view1);
        if (dibujar == true) //si apreto enter empieza el juego
        {
            //menu.draw(window);
            window.draw(fondo);
            window.draw(cuadrante);
            window.draw(car);
            
        }
        else
        {
            window.draw(menu);
        }

        if (ganaste == true)
        {
            window.draw(win);
        }
        //
        window.display();
    }

    return 0;
}