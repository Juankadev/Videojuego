#pragma once
#include "Auto.h"
#include "Collisionable.h"
#include "Cuadrante.h"
#include "Rectangulo.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "NivelMaster.h"

class NIvel1: public NivelMaster
{
    protected:
        /*Auto car;
        Rectangulo rect;
        Cuadrante cuadrante;
        sf::RectangleShape fondo;
        sf::Texture texturefondo;
        sf::Music music;*/

    public:
        /*NIvel1();
        ~NIvel1();
        void updates();
        bool auto_estacionado();
        void colisiones_auto_y_objetos();*/
        NIvel1();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

