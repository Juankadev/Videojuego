#pragma once
#include "Enemigo.h"
#include "Vehiculo.h"
#include "NivelMaster.h"

//#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>

class Nivel2 : public NivelMaster
{
    private:
        sf::RectangleShape _rect7; //agrego un rectangulo en esta nivel
        //Enemigo _enemigo;
        Vehiculo enemy1;
        Vehiculo enemy2;

    public:
        Nivel2();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        void colisiones_auto_y_objetos(float x, float y, float a);
        sf::FloatRect getBoundsAuto();
        void posicionInicial(float x, float y);
        void updates();
};

