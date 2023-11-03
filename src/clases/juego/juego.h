#ifndef CMAKESFMLPROJECT_JUEGO_H
#define CMAKESFMLPROJECT_JUEGO_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../boxeador/Boxeador.h"
#include "../enemy/enemy.h"

class Juego
{
private:
    sf::RenderWindow mWindow;
    sf::CircleShape mPlayer;

    Enemigo enemigo;
    Boxeador jugador;
public:
    Juego();
    void run();
    void handlePlayerInput(sf::Keyboard::Key, bool);
    void processEvents();
    void update();
    void render();

};

#endif //CMAKESFMLPROJECT_JUEGO_H