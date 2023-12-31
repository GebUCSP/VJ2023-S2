#include "../header/jugador.h"

#include <iostream>

Jugador::Jugador(std::string _nombre, int _vida, int _energia, int _dmg, bool npc): Boxeador(_nombre,_vida,_energia,_dmg,npc) {

    posInitial.x = 675.0f;
    posInitial.y = 600.0f;

    sprite.setPosition(posInitial);
    vida_f.setPosition(10,570);
    energia_f.setPosition(10,600);
    nombre_f.setPosition(50,535);

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
            default:
                break;
        }
    }
    if(!isPressed){
        std::fill(directions.begin(), directions.end(),false);
        std::fill(states.begin(), states.end(),false);
    }

    this->sprite.setPosition(posInitial);
    this->sprite.setScale(1.7f,1.7f);
    this->sprite.setTexture(textures[0]);

    if(states[0] || states[1]){
        movement();
    }

}

void Jugador::movement( ){
    dirImg = 0;
    float x= 1.6f;
    if (directions[0]){
        dirImg = 1;
    }else if(directions[2]){
        dirImg = -1;
    }else{
        dirImg = 0;
        x = 1.4f;
    }

    if(states[0]){
        this->sprite.setTexture(textures[2]);
        this->sprite.move(-100.0f * dirImg, -100.0f);
        this->sprite.setScale(x, x);

    }else if(states[1]){
        if(directions[0] || directions[2]){
            this->sprite.move(-50.0f * dirImg, -80.0f);
        }
        this->sprite.setTexture(textures[1]);
    }else{
        this->sprite.setTexture(textures[0]);

    }


}
