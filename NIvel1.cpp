#include "NIvel1.h"
#include <iostream>
using namespace std;

NIvel1::NIvel1()
{
	texturefondo.loadFromFile("assets/Level1.png");
    fondo.setSize(sf::Vector2f(600, 600));
	fondo.setTexture(&texturefondo);

    if (!music.openFromFile("assets/music.wav"))
    {
        cout << "Error al cargar la musica" << endl;
    }

    music.setVolume(5);
    music.setLoop(true);
}
