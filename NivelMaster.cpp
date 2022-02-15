#include "NivelMaster.h"
#include <iostream>
using namespace std;

NivelMaster::NivelMaster()
{
    //car.setPos(100,100);
    //car.setRot(90);
    //texturefondo.loadFromFile("assets/Level1.png");
    //fondo.setSize(sf::Vector2f(600, 600));
    //fondo.setTexture(&texturefondo);
}

NivelMaster::~NivelMaster()
{
    cout << "Destruccion nivel" << endl;
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

void NivelMaster::colisiones_auto_y_objetos(int x, int y)
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
        car.posicionInicial(x, y);
    }
    if (car.getBounds().intersects(rect.getBounds2()))
    {
        car.posicionInicial(x, y);
    }
    if (car.getBounds().intersects(rect.getBounds3()))
    {
        car.posicionInicial(x, y);
    }
    if (car.getBounds().intersects(rect.getBounds4()))
    {
        car.posicionInicial(x, y);
    }
    if (car.getBounds().intersects(rect.getBounds5()))
    {
        car.posicionInicial(x, y);
    }
    if (car.getBounds().intersects(rect.getBounds6()))
    {
        car.posicionInicial(x, y);
    }
}

void NivelMaster::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(fondo, states);
    target.draw(cuadrante, states);
    target.draw(rect, states);
    target.draw(car, states);
}
