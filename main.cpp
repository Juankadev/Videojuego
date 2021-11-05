#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!");


    //TEXTURAS
    sf::Texture texture_bus;
    texture_bus.loadFromFile("assets/car.png");

    sf::Texture texture_fondo;
    if(!texture_fondo.loadFromFile("assets/pasto.jpg")) return -1;

    sf::Texture texture_calle;
    if(!texture_calle.loadFromFile("assets/calle.jpg")) return -1;

    //OBJETOS
    sf::Sprite bus;
    bus.setTexture(texture_bus);
    bus.scale(0.5, 0.5);
    bus.setOrigin(bus.getScale().x / 2, bus.getScale().y / 2);
    

    sf::RectangleShape fondo(sf::Vector2f(1000, 700));
    fondo.setTexture(&texture_fondo);

    sf::RectangleShape calle(sf::Vector2f(1000, 300));
    calle.setPosition(0, 200);
    calle.setTexture(&texture_calle);

    /*sf::RectangleShape enemigo(sf::Vector2f(100, 40));
    enemigo.setFillColor(sf::Color::Black);
    enemigo.setPosition(0, 300);*/

    

    float x = 200;
    float y = 450;
    float rotar = 0;

    float x_enemigo = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            x -= .7f;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            x += .7f;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                y -= .5f;
                rotar -= .4f;
                bus.setRotation(rotar);
                x -= .2f;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                y += .5f;
                rotar += .4f;
                bus.setRotation(rotar);
                x -= .2f;
            }
        }

        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == false)
        {
            y -= .7f;
            //bus.setRotation(90.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            y += .7f;
            //bus.setRotation(90.f);
        }
        

        window.clear();

        bus.setPosition(x, y);

        x_enemigo = x_enemigo + 1;
        //enemigo.setPosition(x_enemigo, 300);

        if (x_enemigo > 1200)
        {
            x_enemigo = -150;
            //enemigo.setPosition(-150, 300);
        }


        window.draw(fondo);
        window.draw(calle);
        //window.draw(enemigo);
        window.draw(bus);

        window.display();
    }


    return 0;
}