#include "../header/jugador.h"

#include <iostream>

Jugador::Jugador(std::string _nombre, int _vida, int _energia, int _dmg): Boxeador(_nombre,_vida,_energia,_dmg) {
    if(!texture.loadFromFile("resource/menu.jpg",sf::IntRect(20,20,20,20))){
        std::cout << "error cargar" << std::endl;
    }

    posInitial.x = 450.0f;
    posInitial.y = 500.0f;

    sprite.setTexture(texture);
    sprite.setScale(6,6);
    sprite.setPosition(450,500);

    if (!font.loadFromFile("resource/arial.ttf"))
    {
        std::cout << "fallo carga fuente" << std::endl;
    }

    vida_f.setFont(font);
    energia_f.setFont(font);
    nombre_f.setFont(font);
    vida_f.setPosition(10,570);
    energia_f.setPosition(10,600);
    nombre_f.setPosition(50,535);

}



void Jugador::move(bool prueba, std::string dir = "none"){
    int x;
    if (dir == "der"){
        x = 1;
    }else if(dir == "izq"){
        x = -1;
    }else{
        x = 0;
    }
    this->sprite.move(-100*x,-100);
}

void Jugador::inputs(sf::Keyboard::Key key, bool isPressed) {

    if(isPressed){
        switch (key) {
            case sf::Keyboard::A:
                changeDirections(0, isPressed);
                break;
            case sf::Keyboard::W:
                changeDirections(1, isPressed);
                break;
            case sf::Keyboard::D:
                changeDirections(2, isPressed);
                break;
            case sf::Keyboard::S:
                changeDirections(3, isPressed);
                break;
            default:
                break;
        }


        switch (key) {
            case sf::Keyboard::J:
                changeStates(0, isPressed);
                break;
            case sf::Keyboard::K:
                changeStates(1, isPressed);
                break;
            case sf::Keyboard::L:
                changeStates(2, isPressed);
                break;
            default:
                break;
        }
    }
    if(!isPressed){
        std::fill(directions.begin(), directions.end(),false);
        std::fill(states.begin(), states.end(),false);
    }

    sprite.setPosition(posInitial);

    if(states[0]){
        if(directions[0]){
            move(isPressed,"der");
        }else if(directions[2]){
            move(isPressed,"izq");
        }else{
            move(isPressed);
        }
    }

    if(states[1]){
        this->sprite.setScale(5,5);
    }else{
        this->sprite.setScale(6,6);
    }



}


void Jugador::timer(Boxeador* enemigo){
    return;
}

