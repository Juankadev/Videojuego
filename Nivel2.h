#pragma once
#include "NIvel1.h"
#include "Enemigo.h"
#include "Vehiculo.h"

class Nivel2 : public NIvel1
{
    private:
        sf::RectangleShape _rect7;
        //Enemigo _enemigo;
        Vehiculo vehiculo;

    public:
        Nivel2();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        void colisiones_auto_y_objetos2();
        sf::FloatRect getBoundsAuto();
        void posicionInicial(float x, float y);
        void updates2();
};

