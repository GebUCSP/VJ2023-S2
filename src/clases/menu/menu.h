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
public:
    Menu(sf::RenderWindow* _window): window{_window}{
        if(!background.loadFromFile("D:\\Proyectos U\\CCOMP\\VJ2023-S2\\src\\clases\\menu\\menu.jpg")){
            std::cerr << "Error al cargar texturas";
        }
        backgroundImage.setTexture(background);

        sf::Vector2u sizeW = window->getSize();
        backgroundImage.setScale(static_cast<float> (sizeW.x) / background.getSize().x, static_cast<float> (sizeW.y) / background.getSize().y);
    }

    void dibujarFondo(){
        window->draw(backgroundImage);
    }
};

#endif //CMAKESFMLPROJECT_MENU_H
