#pragma once
#include "Auto.h"
#include "Collisionable.h"
#include "Cuadrante.h"
#include "Rectangulo.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class NivelMaster: public sf::Drawable
{
    protected:
        Auto car;
        Rectangulo rect;
        Cuadrante cuadrante;
        sf::RectangleShape fondo;
        sf::Texture texturefondo;
        int cant_choques;
        //int seg;

    public:
        NivelMaster();
        void updates();
        bool auto_estacionado();
        void colisiones_auto_y_objetos(float x, float y, float a);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        void setAngleCar(float a);
        int getCantChoques();
        void setCantChoques(int c);
};

