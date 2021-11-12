#include <SFML/Graphics.hpp>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include "Auto.h"
#include "Rectangulo.h"
#include "Cuadrante.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!!");
    sf::View view(sf::FloatRect(600.f, 600.f, 600.f, 600.f));

    Auto car;
    Rectangulo rect;
    Cuadrante cuadrante;
    
    sf::RectangleShape fondo(sf::Vector2f(600, 600));
    sf::Texture texturefondo;
    texturefondo.loadFromFile("assets/fondo2.png");
    fondo.setTexture(&texturefondo);

    
    
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //UPDATE

   
        car.update();   

        //COLLISION
        if (car.isCollision(rect))
        {
            //
        }


        //
        window.clear();


        //DRAW
        //window.setView(view1);
        window.draw(fondo);
        window.draw(cuadrante);
        window.draw(car);
        //
        window.display();
    }

    return 0;
}