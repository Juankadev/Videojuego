#include <SFML/Graphics.hpp>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!!");

    

    //TEXTURAS
    

    sf::Texture texture_arbusto;
    texture_arbusto.loadFromFile("assets/arbusto.png");

    sf::Texture texture_car;

    


    //RANDOM TEXTURE

    /* initialize random seed: */
    srand(time(NULL));

    /* generate secret number between 1 and 10: */
    int ran = 0;
    ran = rand() % 3 + 1;
    //cout << ran << endl;
    switch (ran)
    {
    case 1: 
        texture_car.loadFromFile("assets/car-red.png");
        break;
    case 2:
        texture_car.loadFromFile("assets/car-green.png");
        break;
    case 3:
        texture_car.loadFromFile("assets/car-orange.png");
        break;
    default:
        break;
    }


    //OBJETOS
    sf::Sprite car;
    car.scale(0.5, 0.5);
    car.setOrigin(car.getGlobalBounds().width / 2, 0);
    car.setTexture(texture_car);
    car.setPosition(500, 100);

    

    sf::RectangleShape fondo(sf::Vector2f(1000, 700));
    fondo.setFillColor(sf::Color(100, 100, 100));


    sf::RectangleShape lines[13];
    for (int i = 0; i < 13; i++)
    {
        lines[i].setPosition(sf::Vector2f( (lines[i].getPosition().x + 80) * i, 0));
        lines[i].setSize(sf::Vector2f(5, 150));
    }
    

    sf::Sprite arbusto;
    arbusto.setTexture(texture_arbusto);
    arbusto.setPosition(sf::Vector2f(300, 300));


    sf::Font font;
    font.loadFromFile("assets/game.ttf");

    sf::Text text;
    // select the font
    text.setFont(font); // font is a sf::Font
    // set the string to display
    text.setString("Hello world");
    // set the character size
    text.setCharacterSize(24); // in pixels, not points!
    // set the color
    text.setFillColor(sf::Color::Green);
    // set the text style
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);


    float rotar = 0;
    float velocity = 1;

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
            car.move(-velocity,0);
            //car.setRotation(rotar -= .5f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            car.move(velocity, 0);
            //car.setRotation(rotar += .5f);

            /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
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
            }*/
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            car.move(0,-velocity);
            //car.setRotation(rotar -= .5f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            car.move(0,velocity);
            //car.setRotation(rotar -= .5f);
        }

        
        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == false && sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == false)
        {
            y -= .5f;

            if (car.getRotation() > 0.5 && car.getRotation() < 180)
            {
                car.setRotation(rotar -= .5f); 
                cout << car.getRotation() << endl;
            }

            if (car.getRotation() > 180 && car.getRotation() < 360)
            {
                car.setRotation(rotar += .5f);
                cout << car.getRotation() << endl;
            }

            if (car.getRotation() >= -0.5 && car.getRotation() <= 0.5)
            {
                car.setRotation(0);
            }
           
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == false && sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == false)
        {
            y += .5f;

            if (car.getRotation() > 0.5 && car.getRotation() < 180)
            {
                car.setRotation(rotar += .5f);
                cout << car.getRotation() << endl;
            }

            if (car.getRotation() > 180 && car.getRotation() < 360)
            {
                car.setRotation(rotar -= .5f);
                cout << car.getRotation() << endl;
            }

            if (car.getRotation() >= 180 && car.getRotation() <= 181)
            {
                car.setRotation(180);
            }
        }*/
        

        if(car.getPosition().x < 0)
        { 
            car.setPosition(0, car.getPosition().y);
        }

        if (car.getPosition().y < 0)
        {
            car.setPosition(car.getPosition().x, 0);
        }

        if (car.getPosition().x + car.getGlobalBounds().width > 1000)
        {
            car.setPosition(1000 - car.getGlobalBounds().width, car.getPosition().y);
        }

        if (car.getPosition().y + car.getGlobalBounds().height > 600)
        {
            car.setPosition(car.getPosition().x ,600 - car.getGlobalBounds().height);
        }



        if (car.getGlobalBounds().intersects(arbusto.getGlobalBounds()))
        {
            arbusto.setColor(sf::Color(0,128,0,100));
        }
        else
        {
            arbusto.setColor(sf::Color(0,128,0));
        }




        window.clear();


        //DRAW
        window.draw(fondo);
        for (int i = 0; i < 13; i++)
        {
            window.draw(lines[i]);
        }
        window.draw(text);
        window.draw(car);
        window.draw(arbusto);
        window.display();
    }

    return 0;
}