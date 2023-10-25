#ifndef CMAKESFMLPROJECT_ENEMY_H
#define CMAKESFMLPROJECT_ENEMY_H

#include <random>
#include "boxer.h"



class Bot: public Boxeador{
public:
    Bot(Boxeador* _objetivo, string _nombre, int _vida, int _energia, int _fataque = 3.0, int _fbloque = 3.0, int _fesquive = 3.0): objetivo(_objetivo),fataque{_fataque},fbloqueo{_fbloque}, fesquive{_fesquive},Boxeador(_nombre,_vida,_energia){

        clock.restart();
    }

    int random(){
        random_device rd;
        default_random_engine generator(rd());
        uniform_int_distribution<int> distribution(1,3);
        int random = distribution(generator);
        return random;
    }

    void timer(){
        ultimaAccion = clock.getElapsedTime().asSeconds();
        if(ultimaAccion > fataque){
            accionRandom(random());
            clock.restart();
        }
    }

    void accionRandom(int num){
        if(num==1){
            attack(objetivo);
        }else if(num==2){
            attack(objetivo);
        }else if(num==3){
            attack(objetivo);
        }
    }

    void attack(Boxeador* obj){        //!obj->getRange() && !obj->block
        if(true){
            cout << "bajo ataque" << endl;
            obj->setVida(obj->getVida()-10);
            cout << "vida objetivo: " << obj->getVida() << endl;
        }
    }


private:
    bool range = true;
    int fataque, fbloqueo, fesquive;
    int ultimaAccion = 0.0;
    Boxeador* objetivo;
    Clock clock;
};


#endif //CMAKESFMLPROJECT_ENEMY_H
