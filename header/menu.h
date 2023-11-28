#ifndef CMAKESFMLPROJECT_MENU_H
#define CMAKESFMLPROJECT_MENU_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <SFML/Window/Mouse.hpp>

class Menu{
    friend class Juego;
private:

    bool a_play = false , a_options = false , a_back = false;

    sf::RenderWindow* window;
    sf::Texture background;
    sf::Sprite backgroundImage;

    sf::RectangleShape play,options,back;

public:
    //Constructor
    Menu(sf::RenderWindow*);

    //Funcion para chekear el presionado del mouse
    void checkMouseClick1();
    void checkMouseClick2();

    //Para dibujar el fondo y los botones
    void dibujarFondo();
};

#endif //CMAKESFMLPROJECT_MENU_H
