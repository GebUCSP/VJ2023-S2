#include <random>
#include <iostream>
#include "enemy.h"

Enemigo::Enemigo(Boxeador * _jugador, std::string _nombre, int _vida, int _energia, int _dmg, int _cd, int _frecuencia):
    objetivo{_jugador},
    frecuencia(_frecuencia),
    Boxeador(_nombre,_vida,_energia, _dmg){
        cd.restart();
        clock.restart();
    }

int Enemigo::random(){
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution (1,3);
    int random =distribution(generator);
    return random;
}

void Enemigo::timer(){
    ultimaAccion = clock.getElapsedTime().asSeconds();

    if(ultimaAccion > frecuencia){
        accionRandom(random());
        clock.restart();
    }

    if(ultimaAccion > frecuencia/2){
        this->states[1] = true;
    } else{
        this->states[1] = false;
    }
}

void Enemigo::accionRandom(int num){
    if(num==1){
        attack();
    }else if(num == 3){
        attack();
    }else{
        attack();
    }
    //atacando(1), bloqueando(2), esquivando(3)
}

void Enemigo::attack() {
    if(!objetivo->getRange()){
        this->changeRange();
        std::cout << "bajo ataque" << std::endl;
        objetivo->setVida(objetivo->getVida()-10);
        std::cout << "vida objetivo: " << objetivo->getVida() << std::endl;
    }else{
        std::cout << "Ataque Bloqueado" << std::endl;
    }
}