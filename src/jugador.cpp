#include "../header/jugador.h"

#include <iostream>

Jugador::Jugador(std::string _nombre, int _vida, int _energia, int _dmg): Boxeador(_nombre,_vida,_energia,_dmg) {}

void Jugador::drawMe() {
    return;
}

void Jugador::inputs(sf::Keyboard::Key key, bool isPressed) {

    for(auto direction: directions){
        isPressed = !direction && isPressed;
    }

    for(auto state: states){
        isPressed = !state && isPressed;
    }

    switch (key) {
        case sf::Keyboard::A:
            changeDirections(0, isPressed);
            break;
        case sf::Keyboard::W:
            changeDirections(1,isPressed);
            break;
        case sf::Keyboard::D:
            changeDirections(2,isPressed);
            break;
        case sf::Keyboard::S:
            changeDirections(3,isPressed);
            break;
        default:
            break;
    }


    switch (key) {
        case sf::Keyboard::J:
            changeStates(0, isPressed);
            break;
        case sf::Keyboard::K:
            changeStates(1,isPressed);
            break;
        case sf::Keyboard::L:
            changeStates(2,isPressed);
            break;
        default:
            break;
    }

}

void Jugador::timer(Boxeador* enemigo){
    return;
}

