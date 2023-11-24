#ifndef CMAKESFMLPROJECT_MENU_H
#define CMAKESFMLPROJECT_MENU_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <SFML/Window/Mouse.hpp>

class Menu{
    friend class Juego;
private:

    bool:: a_play= false,a_options= false;

    sf::RenderWindow* window;
    sf::Texture background;
    sf::Sprite backgroundImage;

    sf::RectangleShape play,options;

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

        //boton play
        play.setPosition(static_cast<float>(sizeW.x)-180,static_cast<double>(sizeW.y)-200);
        play.setSize(sf::Vector2f (300,100));
        play.setFillColor(sf::Color::Transparent);
        //boton options
        options.setPosition(static_cast<float>(sizeW.x)-180,static_cast<double>(sizeW.y)-100);
        options.setSize(sf::Vector2f (550,100));
        options.setFillColor(sf::Color::Transparent);
    }

    void checkMouseClick(){
        sf::Vector2i mousePos = sf::Mouse::getPosition();
        sf::Vector2f mousePosCoords = window->mapPixelToCoords(mousePos);

        if (play.getGlobalBounds().contains(mousePosCoords)){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                a_play= true;
                std::cout << "Play presionado" << std::endl;
            }
        }
        if (options.getGlobalBounds().contains(mousePosCoords)){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                a_options= true;
                std::cout << "Options presionado" << std::endl;
            }
        }
    }

    void dibujarFondo(){
        window->draw(backgroundImage);
        window->draw(play);
    }


};

#endif //CMAKESFMLPROJECT_MENU_H