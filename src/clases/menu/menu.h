#ifndef CMAKESFMLPROJECT_MENU_H
#define CMAKESFMLPROJECT_MENU_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Texture.hpp"


class Menu{
    friend class Juego;
private:

    sf::RenderWindow* window;
    sf::Texture background;
    sf::Sprite backgroundImage;

    sf::RectangleShape play;
public:
    //Constructor
    Menu(sf::RenderWindow* _window): window{_window}{
        if(!background.loadFromFile("src/clases/menu/menu.jpg")){
            std::cerr << "Error al cargar texturas";
        }
        backgroundImage.setTexture(background);

        //fondo
        sf::Vector2u sizeW = window->getSize();
        backgroundImage.setScale(static_cast<float> (sizeW.x) / background.getSize().x, static_cast<float> (sizeW.y) / background.getSize().y);

        //boton
        play.setPosition(50,50);
        play.setSize(sf::Vector2f (50,50));
        play.setFillColor(sf::Color::Cyan);
    }

    void checkMouseClick(){
        sf::Vector2i mousePos = sf::Mouse::getPosition();
        sf::Vector2f mousePosCoords = window->mapPixelToCoords(mousePos);

        if (play.getGlobalBounds().contains(mousePosCoords)){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                std::cout << "se logro" << std::endl;
            }
        }
    }

    void dibujarFondo(){
        window->draw(backgroundImage);
        window->draw(play);
    }


};

#endif //CMAKESFMLPROJECT_MENU_H
