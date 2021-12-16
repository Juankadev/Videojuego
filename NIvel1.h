#pragma once
#include "Auto.h"
#include "Collisionable.h"
#include "Cuadrante.h"
#include "Rectangulo.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class NIvel1
{
    private:
        Auto car;
        Rectangulo rect;
        Cuadrante cuadrante;
    
    public:
        NIvel1();
        sf::RectangleShape fondo;
        sf::Texture texturefondo;
        sf::Music music;
        
};

