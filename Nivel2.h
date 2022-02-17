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
        Vehiculo vehiculo;

    public:
        Nivel2();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        void colisiones_auto_y_objetos(int x, int y);
        sf::FloatRect getBoundsAuto();
        void posicionInicial(float x, float y);
        void updates2();
};

