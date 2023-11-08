#include <random>
#include <iostream>
#include "enemy.h"


//Constructor clase Enemigo
Enemigo::Enemigo(Boxeador * _jugador, std::string _nombre, int _vida, int _energia, int _dmg, int _frecuencia):
    objetivo{_jugador},
    //Se encarga de la frecuencia de los actaques
    frecuencia(_frecuencia),
    Boxeador(_nombre,_vida,_energia, _dmg){
        //Reinicia el tiempo del ultimo ataque
        clock.restart();
    }


    //genera un numero random y lo devuelve
int Enemigo::random(){
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution (1,3);
    int random =distribution(generator);
    return random;
}

//determina cada cuanto golpea el enemigo
void Enemigo::timer(){
    //reloj medido en segundos
    ultimaAccion = clock.getElapsedTime().asSeconds();

    //cuando termine la ultima accion se realiza otra accion
    if(ultimaAccion > frecuencia){
        //lamada a accionRandom
        accionRandom(random());
        //reinicia su reloj
        clock.restart();
    }

    //Bloquea mientras se encuentre en la mitad de su frecuencia y luego baja la guarda para realizar una accion
    if(ultimaAccion > frecuencia/2){
        this->states[1] = true;
    } else{
        this->states[1] = false;
    }

}

//determina la accion con el numero aleatorio (falta integrar toas las acciones)
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

//Enemigo ataca al jugador
void Enemigo::attack() {
    if(!objetivo->getRange() && !objetivo->getStates(1) && !objetivo->getStates(2)){
        this->changeRange();
        std::cout << "bajo ataque" << std::endl;
        objetivo->setVida(objetivo->getVida()-10);
        std::cout << "vida objetivo: " << objetivo->getVida() << std::endl;
    }else{
        std::cout << std::endl;
    }
}