#include "Nivel2.h"
#include <iostream>
using namespace std;

Nivel2::Nivel2()
{
    //car
    car.setPos(550, 500);
    car.setRot(-90);
    //fondo
    texturefondo.loadFromFile("assets/Level2.png");
    fondo.setSize(sf::Vector2f(600, 600));
    fondo.setTexture(&texturefondo);

    

    //Rectangulos objetos
    //rect.setPosRect1(0, 0); //NO FUNCA (algo de const override? )
    rect.setPosRect2(0, 0);
    rect.setPosRect3(490, 0);
    rect.setPosRect4(150,410);
    rect.setPosRect5(340, 550);
    rect.setPosRect6(266, 70);
    rect.setPosCircle(130, 420);
    _rect7.setPosition(490,135);

    rect.setSizeRect2(110,180);
    rect.setSizeRect3(110, 60);
    rect.setSizeRect4(500, 33);
    rect.setSizeRect5(180, 80);
    rect.setSizeRect6(96, 55);
    _rect7.setSize(sf::Vector2f(110, 60));
    rect.setSizeCircle(43);

    //cuadrante(donde estaciona)
    cuadrante.setPos(580, 72);
    cuadrante.setRot(90);
}


void Nivel2::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(fondo, states);
    target.draw(cuadrante, states);
    //target.draw(rect, states);
    //target.draw(_rect7, states);
    target.draw(car, states);
    target.draw(vehiculo, states);
}

void Nivel2::colisiones_auto_y_objetos2()
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
        car.posicionInicial(550, 500);
    }
    if (car.getBounds().intersects(rect.getBounds2()))
    {
        car.posicionInicial(550, 500);
    }
    if (car.getBounds().intersects(rect.getBounds3()))
    {
        car.posicionInicial(550, 500);
    }
    if (car.getBounds().intersects(rect.getBounds4()))
    {
        car.posicionInicial(550, 500);
    }
    if (car.getBounds().intersects(rect.getBounds5()))
    {
        car.posicionInicial(550, 500);
    }
    if (car.getBounds().intersects(rect.getBounds6()))
    {
        car.posicionInicial(550, 500);
    }
    if (car.getBounds().intersects(_rect7.getGlobalBounds()))
    {
        car.posicionInicial(550, 500);
    }
    if (car.getBounds().intersects(vehiculo.getBounds()))
    {
        car.posicionInicial(550, 500);
    }
}

sf::FloatRect Nivel2::getBoundsAuto()
{
    return car.getBounds();
}

void Nivel2::posicionInicial(float x, float y)
{
    car.setPos(x, y);
}

void Nivel2::updates2()
{
    vehiculo.update();
}