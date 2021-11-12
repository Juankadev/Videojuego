#include "Cuadrante.h"

void Cuadrante::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(cuadrante, states);
}

void Cuadrante::draw(sf::RenderWindow& window)
{
    window.draw(cuadrante);
}

sf::FloatRect Cuadrante::getBounds() const
{
    return _cuadrante.getGlobalBounds();
}

Cuadrante::Cuadrante()
{
    _texture.loadFromFile("assets/cuadrante.png");
    _cuadrante.setTexture(_texture);
    _cuadrante.scale(0.45, 0.7);
    //cuadrante.setFillColor(sf::Color::White);
    //cuadrante.setOutlineThickness(3);
    //cuadrante.setOutlineColor(sf::Color::Yellow);
    _cuadrante.setPosition(260, 20);



    cuadrante.setFillColor(sf::Color::White);
   //cuadrante.setOutlineThickness(3);
   //cuadrante.setOutlineColor(sf::Color::Yellow);
    cuadrante.setSize({50,50});

}
