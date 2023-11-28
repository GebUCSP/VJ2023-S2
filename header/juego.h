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




public:
    Juego();
    ~Juego();

    void run();
    void render();
    void eventos();

    void datos();
};



#endif //CMAKESFMLPROJECT_JUEGO_H
