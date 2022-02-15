#include "NIvel1.h"
#include <iostream>
using namespace std;
/*
NIvel1::NIvel1()
{
    //car.setPos(40,60);
    //car.setRot(90);
    car.setPos(180, 350);
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
*/
NIvel1::NIvel1()
{
    car.setPos(100, 100);
    car.setRot(90);
    texturefondo.loadFromFile("assets/Level1.png");
    fondo.setSize(sf::Vector2f(600, 600));
    fondo.setTexture(&texturefondo);

    rect.setSizeRect1(410,40);
    rect.setPosRect1(0,0);
    
    rect.setSizeRect2(410, 40);
    rect.setPosRect2(0, 200);

    rect.setSizeRect3(330, 100);
    rect.setPosRect3(65, 240);

    rect.setSizeRect4(105, 100);
    rect.setPosRect4(65, 480);

    rect.setSizeRect5(200, 90);
    rect.setPosRect5(235, 480);

    rect.setSizeRect6(420, 40);
    rect.setPosRect6(0, 5);

    rect.setPosCircle(450,-30);
    rect.setRadiusCircle(70);

    //NivelMaster::colisiones_auto_y_objetos(100, 100);
}

void NIvel1::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //target.draw(fondo, states);
    //target.draw(cuadrante, states);
    //target.draw(rect, states);
    //target.draw(car, states);
    NivelMaster::draw(target,states);
}
