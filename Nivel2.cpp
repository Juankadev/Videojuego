#include "Nivel2.h"
#include <iostream>
using namespace std;

Nivel2::Nivel2()
{
    //car
    //car.setPos(530, 400);
    //car.setRot(-90);
    car.setAngle(-1.6);
    cout << "l2" << endl;
    //fondo
    texturefondo.loadFromFile("assets/Level2.png");
    fondo.setSize(sf::Vector2f(600, 600));
    fondo.setTexture(&texturefondo);

    //Rectangulos objetos
    //rect.setPosRect1(0, 0); //NO FUNCIONA (algo de const override? )
    rect.setPosRect2(0, 0);
    rect.setPosRect3(490, 0);
    rect.setPosRect4(150,410);
    rect.setPosRect5(340, 550);
    rect.setPosRect6(275, 80);
    rect.setPosCircle(130, 420);
    _rect7.setPosition(490,145);

    rect.setSizeRect2(110,160);
    rect.setSizeRect3(110, 45);
    rect.setSizeRect4(500, 33);
    rect.setSizeRect5(180, 80);
    rect.setSizeRect6(70, 40);

    _rect7.setSize(sf::Vector2f(110, 40));
    rect.setRadiusCircle(43);

    //cuadrante(donde estaciona)
    cuadrante.setPos(580, 72);
    cuadrante.setRot(90);
}


void Nivel2::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    NivelMaster::draw(target, states);
    target.draw(vehiculo, states);
    //target.draw(_rect7, states);
}


void Nivel2::colisiones_auto_y_objetos(float x, float y, float a)
{
    //colision objetos
    //if (car.getBounds().intersects(rect.getBounds()))
    //{
        //fondo.setFillColor(sf::Color(255,255,255,50));
        //car.getSoundChoque().play();
        //dibujar = false;
        //car.posicionInicial();
    //}
    NivelMaster::colisiones_auto_y_objetos(x, y, a);

    if (car.getBounds().intersects(_rect7.getGlobalBounds()))
    {
        car.respawn(x,y,-a);
        car.setAngle(a);
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
