#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <ctime> 
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
#include "Tutorial.h"
#include "Vehiculo.h"
#include "NivelMaster.h"
#include <windows.h>

using namespace std;


int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "I DRIVE!", sf::Style::Titlebar | sf::Style::Close);
    sf::View view(sf::FloatRect(600.f, 600.f, 600.f, 600.f));

    Menu menu;
    FinNivel win;
    NIvel1 nivel1;
    Nivel2 nivel2;
    Tutorial tutorial;
    NivelMaster master;


    bool dibujar = false;
    bool dibujar_tuto = false;
    bool ganaste = false;
    int cambiarnivel = false;
    int numerodenivel = 0;
    bool ejecutado1 = false;
    bool ejecutado2 = false;
    int contmenu = 0;

    //---------M U S I C A-----------------------------------//
    //Music Menu
    sf::Music music_menu;
    if (!music_menu.openFromFile("assets/music_menu.ogg"))
    {cout << "Error al cargar la musica menu" << endl;}
    music_menu.setVolume(20);////////////
    music_menu.setLoop(true);
    music_menu.play();

    //Music Game
    sf::Music music_game;
    if (!music_game.openFromFile("assets/music.wav"))
    {cout << "Error al cargar la musica game" << endl;}
    music_game.setVolume(10);////////////////
    music_game.setLoop(true);

    //Sound Win
    sf::SoundBuffer sound_win_buffer;
    if (!sound_win_buffer.loadFromFile("assets/sound_win.ogg"))
    {
        cout << "Error al cargar sound win" << endl;
    }

    sf::Sound sound_win;
    sound_win.setBuffer(sound_win_buffer);
    sound_win.setVolume(40);


    //cout << "Menu: " << menu.getChoques() << endl;
    
    //----------------------------------------------------------------------------------
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
        
        if (contmenu == 0)
        {
            if (menu.seleccionar_opcion()) //si apretó enter
            {
                dibujar_tuto = true;
                //music.resetBuffer();
                contmenu++;
            }
        }

        if (contmenu < 2) //para apretar salir en el menu y en el tutorial
        {
            if (menu.seleccionar_opcion()==2) //si apretó 'S' sale
            {
                contmenu++;
                break;
                //music.resetBuffer();
            }
        }


        if (tutorial.seleccionar_opcion())
        {
            dibujar = true; //dibuja el juego
            dibujar_tuto = true; //no se vuelve a dibujar el tutorial
            numerodenivel = 1;
            contmenu++;
            cout << "TUTORIAL" << endl;
            music_menu.stop();
            music_game.play();
        }


        

        //UPDATES
        switch (numerodenivel) //para niveles
        {
        case 0:
            menu.animationText();
            tutorial.animationText();
            break;
        case 1:
            nivel1.updates();
            nivel1.auto_estacionado();//colision cuadrante para estacionar
            nivel1.colisiones_auto_y_objetos(100, 100, 1.6); //los parametros son los valores de respawn al colisionar
            break;

        case 2:
            nivel2.updates();
            nivel2.auto_estacionado();//colision cuadrante para estacionar
            nivel2.colisiones_auto_y_objetos(540, 480, -1.6);//colision objetos
            break;
        }
         

        ////////////////
        window.clear();


        //DRAW

        //cuando apreto enter empieza el juego

        if (dibujar_tuto == false)
        {
            window.draw(menu);
        }
        else
        {
            window.draw(tutorial);
        }
        //////////
        switch (numerodenivel) //para niveles
        {
            case 1:
                window.draw(nivel1);   
                break;

            case 2:
                window.draw(nivel2);
                break;
        }


        //hacer que solo se ejecute una vez
        //SI ESTACIONO BIEN

        if (nivel1.auto_estacionado() == true)
        {
            //para que se repita una vez el codigo de aumentar el nivel
            if (ejecutado1 == false)
            {
                //window.draw(win);
                //dibujar = false; //me lleva al menu
                cambiarnivel = true;
                ejecutado1 = true;
                sound_win.play();
                Sleep(1000);
            }
            //nivel1.~NIvel1();
        }


        if (nivel2.auto_estacionado() == true)
        {
            //para que se repita una vez el codigo de aumentar el nivel
            if (ejecutado2 == false)
            {
                //window.draw(win);
                //dibujar = false; //me lleva al menu
                cambiarnivel = true;
                ejecutado2 = true;
                sound_win.play();
                Sleep(1000);
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
            dibujar_tuto = false;
            numerodenivel = 0;
            contmenu = 0;
            menu.setCont(0); //resetea el contador de cuando se apreta enter, para que no se ejecute varias veces
            tutorial.setCont(0);
            music_game.stop();
            music_menu.play();
            menu.grabarEnDisco(nivel1.getCantChoques() + nivel2.getCantChoques()); //grabo la cantidad de choques
            nivel1.setCantChoques(0); //reinicio valor para la proxima partida
            nivel2.setCantChoques(0); //reinicio valor para la proxima partida
        }
        //
        window.display();
    }

    return 0;
}