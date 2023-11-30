#ifndef CMAKESFMLPROJECT_JUEGO_H
#define CMAKESFMLPROJECT_JUEGO_H


#include "SFML/Graphics.hpp"

#include <iostream>

#include "../header/juego.h"
#include "../header/boxeador.h"
#include "../header/jugador.h"
#include "../header/enemigo.h"
#include "../header/menu.h"


class Juego{
private:
    sf::RenderWindow mWindow;

    Menu menu;

    Boxeador* player;
    Boxeador* enemigo;

    sf::Texture background;
    sf::Sprite s_background;

    sf::Texture cuerdas;
    sf::Sprite s_cuerdas;

    sf::Texture win;
    sf::Sprite s_win;

    sf::Texture over;
    sf::Sprite s_gameOver;



public:
    Juego();
    ~Juego();

    void run();
    void render();
    void eventos();

};



#endif //CMAKESFMLPROJECT_JUEGO_H
