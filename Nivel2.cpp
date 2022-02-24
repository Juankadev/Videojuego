#include "Nivel2.h"
#include <iostream>
using namespace std;

Nivel2::Nivel2()
{
    enemy1.setPos(0, 350);
    enemy1.setMove(0.4);
    enemy1.setRot(90);
    enemy1.setRespawn(0, 350);

    enemy2.setPos(650, 270);
    enemy2.setMove(0.6);
    enemy2.setRot(90);
    enemy2.setRespawn(-200, 270);
    //car
    //car.setPos(530, 400);
    //car.setRot(-90);
    car.setAngle(-1.6);
    //fondo
    texturefondo.loadFromFile("assets/Level2.png");
    fondo.setSize(sf::Vector2f(600, 600));
    fondo.setTexture(&texturefondo);

    //Rectangulos objetos
    //rect.setPosRect1(0, 0); //NO FUNCIONA (algo de const override? )
    rect.setPosRect2(0, 0);//
    rect.setPosRect3(490, 0);//
    rect.setPosRect4(150,410);//
    rect.setPosRect5(360, 550); //trampa 1
    rect.setPosRect6(275, 100);//plaza
    rect.setPosCircle(140, 430);
    _rect7.setPosition(510,145);//colision auto verded derecha

    rect.setSizeRect2(110,160);
    rect.setSizeRect3(110, 32);
    rect.setSizeRect4(500, 33);
    rect.setSizeRect5(150, 80); //trampa 1
    rect.setSizeRect6(50, 20);//plaza

    _rect7.setSize(sf::Vector2f(110, 40));
    rect.setRadiusCircle(30);

    //cuadrante(donde estaciona)
    cuadrante.setPos(580, 72);
    cuadrante.setRot(90);
    
    car.respawn(550, 470, -1.6);
}


void Nivel2::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    NivelMaster::draw(target, states);
    target.draw(enemy1, states);
    target.draw(enemy2, states);
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

    if (car.getBounds().intersects(enemy1.getBounds()))
    {
        car.respawn(x, y, -a);
        car.setAngle(a);
        cant_choques++;
        cout << "Intersecta" << endl;
    }

    if (car.getBounds().intersects(enemy2.getBounds()))
    {
        car.respawn(x, y, -a);
        car.setAngle(a);
        cant_choques++;
        cout << "Intersecta" << endl;
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

void Nivel2::updates()
{
    NivelMaster::updates();
    enemy1.update();
    enemy2.update();
}
