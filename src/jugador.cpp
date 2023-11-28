#include "../header/jugador.h"

#include <iostream>

Jugador::Jugador(std::string _nombre, int _vida, int _energia, int _dmg): Boxeador(_nombre,_vida,_energia,_dmg) {
    t_golpes.resize(t_golpes_dir.size());
    for(int i = 0; i < t_golpes_dir.size(); i++) {
        if (!t_golpes[i].loadFromFile(t_golpes_dir[i]))
            std::cout << "Error cargar textura" << std::endl;
        s_golpes.setTexture(t_golpes[i]);
        s_golpes.setTextureRect(sf::IntRect(0,0, 256, 256));
        s_golpes.setScale(4,4);
    }
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
            drawMe(s_golpes,t_golpes[1]);
            this->check2();
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

void Jugador::check1() {
        if (this->tiempos_g_temp[1]) {
            drawMe(this->s_golpes,this->t_golpes[1]);
            this->tiempos_g_temp[1] --;
        }
        if (this->tiempos_g_temp[1] == 0) {
            this->OK = false;
        }
}

void Jugador::check2(){
    this->OK = true;
    tiempos_g_temp = tiempos_g;
}