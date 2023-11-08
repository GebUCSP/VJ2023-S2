#ifndef CMAKESFMLPROJECT_JUEGO_H
#define CMAKESFMLPROJECT_JUEGO_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../boxeador/Boxeador.h"
#include "../enemy/enemy.h"
#include "../menu/menu.h"

class Juego
{
private:
    //ventana del juego
    sf::RenderWindow mWindow;

    //pruebas de dibujo del jugador (OMITIR)
    sf::CircleShape mPlayer;

    //Menú

    Menu menu;

    //Enemigo
    Enemigo enemigo;

    //Jugador
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