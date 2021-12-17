#include "NIvel1.h"
#include <iostream>
using namespace std;

NIvel1::NIvel1()
{
    car.setPos(40,60);
    //car.setRot(90);
	texturefondo.loadFromFile("assets/Level1.png");
    fondo.setSize(sf::Vector2f(600, 600));
	fondo.setTexture(&texturefondo);

}

NIvel1::~NIvel1()
{
    cout << "Destruccion nivel 1" << endl;
}

void NIvel1::updates()
{
    car.update();
}

bool NIvel1::auto_estacionado()
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

void NIvel1::colisiones_auto_y_objetos()
{
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
        car.posicionInicial(20,50);
    }
    if (car.getBounds().intersects(rect.getBounds2()))
    {
        car.posicionInicial(20, 50);
    }
    if (car.getBounds().intersects(rect.getBounds3()))
    {
        car.posicionInicial(20, 50);
    }
    if (car.getBounds().intersects(rect.getBounds4()))
    {
        car.posicionInicial(20, 50);
    }
    if (car.getBounds().intersects(rect.getBounds5()))
    {
        car.posicionInicial(20, 50);
    }
    if (car.getBounds().intersects(rect.getBounds6()))
    {
        car.posicionInicial(20, 50);
    }
}

void NIvel1::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(fondo, states);
    target.draw(cuadrante, states);
    //target.draw(rect, states);
    target.draw(car, states);
}
