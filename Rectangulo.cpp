#include "Rectangulo.h"

Rectangulo::Rectangulo()
{
    for (int i = 0; i < 5; i++)
    {
        _rect[i].setFillColor(sf::Color(255, 0, 0, 50));
    }

    _rect[0].setSize({420,40});
    _rect[0].setPosition(0, 0);
    //
    _rect[1].setSize({ 420,40 });
    _rect[1].setPosition(0, 200);
    //
    _rect[2].setSize({ 330,100 });
    _rect[2].setPosition(65, 240);
    //
    _rect[3].setSize({ 105,100 });
    _rect[3].setPosition(65, 480);
    //
    _rect[4].setSize({ 200,90 });
    _rect[4].setPosition(235, 480);
    //
    _circ.setRadius(65);
    _circ.setPosition(450, -30);
    _circ.setFillColor(sf::Color(255,0,0,100));
    
}

void Rectangulo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (int i = 0; i < 5; i++)
    {
        target.draw(_rect[i], states);
    }
}

sf::FloatRect Rectangulo::getBounds() const
{
    return _rect[0].getGlobalBounds();
}

sf::FloatRect Rectangulo::getBounds1()
{
    return _rect[1].getGlobalBounds();
}

sf::FloatRect Rectangulo::getBounds2()
{
    return _rect[2].getGlobalBounds();
}

sf::FloatRect Rectangulo::getBounds3()
{
    return _rect[3].getGlobalBounds();
}

sf::FloatRect Rectangulo::getBounds4()
{
    return _rect[4].getGlobalBounds();
}

sf::FloatRect Rectangulo::getBounds5()
{
    return _circ.getGlobalBounds();
}
