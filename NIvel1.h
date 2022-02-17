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

    public:
        NIvel1();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

