#include "NivelMaster.h"
#include <iostream>
#include <windows.h>
using namespace std;

NivelMaster::NivelMaster()
{
    //car.setPos(100,100);
    //car.setRot(90);
    //texturefondo.loadFromFile("assets/Level1.png");
    //fondo.setSize(sf::Vector2f(600, 600));
    //fondo.setTexture(&texturefondo);
    cant_choques = 0;

    /*if (!music.openFromFile("assets/music.wav"))
    {
        cout << "Error al cargar la musica" << endl;
    }
    music.setVolume(10);
    music.setLoop(true);
    music.play();*/
}


void NivelMaster::updates()
{
    car.update();
}

bool NivelMaster::auto_estacionado()
{
    //colision cuadrante para estacionar
    if (cuadrante.getBounds().top < car.getBounds().top) //CALCULOS PARA SABER SI EL AUTO ENTRO AL CUADRANTE
    {
        if (cuadrante.getBounds().left < car.getBounds().left)
        {
            if (cuadrante.getBounds().left + cuadrante.getBounds().width > car.getBounds().left + car.getBounds().width)
            {
                if (cuadrante.getBounds().top + cuadrante.getBounds().height > car.getBounds().top + car.getBounds().height)
                {
                    //dibujar = false; //para dibujar el menu
                    //ganaste = true;
                    return true;
                }
            }
        }
    }

    return false;
}

void NivelMaster::colisiones_auto_y_objetos(float x, float y, float a)
{
    //PARA MEJORAR, un for que pregunte por todas las intersecciones, hay que ir variando el numero de getBounds"1"
    //concatenar cadenas con strcpy

    //colision objetos
    //if (car.getBounds().intersects(rect.getBounds()))
    //{
        //fondo.setFillColor(sf::Color(255,255,255,50));
        //car.getSoundChoque().play();
        //dibujar = false;
        //car.posicionInicial();
    //}
    if (car.getBounds().intersects(rect.getBounds1()))
    {
        //car.setPos(100, 100);
        //car.setAngle(a);
        car.respawn(x,y,a);

        cant_choques++;
        cout << "Intersecta" << endl;
    }
    if (car.getBounds().intersects(rect.getBounds2()))
    {
        car.respawn(x,y,a);
        cant_choques++;
        cout << "Intersecta" << endl;
    }
    if (car.getBounds().intersects(rect.getBounds3()))
    {
        car.respawn(x,y,a);
        cant_choques++;
        cout << "Intersecta" << endl;
    }
    if (car.getBounds().intersects(rect.getBounds4()))
    {
        car.respawn(x,y,a);
        cant_choques++;
        cout << "Intersecta" << endl;
    }
    if (car.getBounds().intersects(rect.getBounds5()))
    {
        car.respawn(x, y, a);
        cant_choques++;
        cout << "Intersecta" << endl;
    }
    if (car.getBounds().intersects(rect.getBounds6()))
    {
        car.respawn(x,y,a);
        cant_choques++;
        cout << "Intersecta" << endl;
    }
}

void NivelMaster::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(fondo, states);
    target.draw(cuadrante, states);
    //target.draw(rect, states); //muestra colisiones
    target.draw(car, states);
}

void NivelMaster::setAngleCar(float a)
{
    //car.setAngle(a);
}

int NivelMaster::getCantChoques()
{
    return cant_choques;
}
