#ifndef CMAKESFMLPROJECT_MENU_H
#define CMAKESFMLPROJECT_MENU_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <SFML/Window/Mouse.hpp>

class Menu{
    friend class Juego;
private:

    bool a_play=false , a_options= false;

    sf::RenderWindow* window;
    sf::Texture background;
    sf::Sprite backgroundImage;

    sf::RectangleShape play,options;

public:
    //Constructor
    Menu(sf::RenderWindow* _window): window{_window}{
        //Comprobacion si el achivo llego a cargar o no
        if(!background.loadFromFile("src/clases/menu/menu.jpg")){
            std::cerr << "Error al cargar texturas";
        }
        backgroundImage.setTexture(background);

        //Set del fondo
        sf::Vector2u sizeW = window->getSize();
        backgroundImage.setScale(static_cast<float> (sizeW.x) / background.getSize().x, static_cast<float> (sizeW.y) / background.getSize().y);

        //boton play *posicion , tamaño y transparencia
        play.setPosition(static_cast<float>(sizeW.x)-180,static_cast<double>(sizeW.y)-200);
        play.setSize(sf::Vector2f (300,100));
        play.setFillColor(sf::Color::Transparent);
        //boton options *posicion , tamaño y transparencia
        options.setPosition(static_cast<float>(sizeW.x)-180,static_cast<double>(sizeW.y)-100);
        options.setSize(sf::Vector2f (550,100));
        options.setFillColor(sf::Color::Transparent);
    }

    //Funcion para chekear el presionado del mouse
    void checkMouseClick(){
        sf::Vector2i mousePos = sf::Mouse::getPosition();
        sf::Vector2f mousePosCoords = window->mapPixelToCoords(mousePos);

        //Detectar si se ha oprimido el boton play
        if (play.getGlobalBounds().contains(mousePosCoords)){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                a_play= true;
                std::cout << "Play presionado" << std::endl;
            }
        }

        //Detectar si se ha oprimido el boton options
        if (options.getGlobalBounds().contains(mousePosCoords)){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                a_options= true;
                std::cout << "Options presionado" << std::endl;
            }
        }
    }

    //Para dibujar el fondo y los botones
    void dibujarFondo(){
        window->draw(backgroundImage);
        window->draw(play);
        window->draw(options);
    }

    //Para detectar fuera de la clase si se ha oprimido el boton play o el options
    bool play_s()const{
        return this->a_play;
    }
    bool options_s()const{
        return a_options;
    }

};

#endif //CMAKESFMLPROJECT_MENU_H