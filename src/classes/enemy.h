#ifndef CMAKESFMLPROJECT_ENEMY_H
#define CMAKESFMLPROJECT_ENEMY_H

#include <random>
#include "boxer.h"



class Bot: public Boxeador{
public:
    Bot(Boxeador* _objetivo, string _nombre, int _vida, int _energia,int _cd, int _dmg, int _fataque = 2.0, int _fesquive = 3.0):
    objetivo(_objetivo),
    fataque{_fataque},
    fbloqueo{_fataque - 1},
    fesquive{_fesquive},
    Boxeador(_nombre,_vida,_energia, _cd, _dmg)
    {
        cd.restart();
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
        if(ultimaAccion > fbloqueo){
            cout << ultimaAccion << "\t" << fataque/fbloqueo;
            cout << "Enemigo bloqueando: " << block << endl;
            block = false;
        }
        if(ultimaAccion > fataque){
            accionRandom(random());
            clock.restart();
        }

    }

    void accionRandom(int num){
        if(num==1){
            attack(objetivo);
        }else if(num==3){
            attack(objetivo);
        }else{
            attack(objetivo);
        }
        //atacando(1), bloqueando(2), esquivando(3)

    }

    void attack(Boxeador* obj){        //!obj->getRange() && !obj->block
        if(!obj->getRange()){
            setRange(true);
            cout << "bajo ataque" << endl;
            obj->setVida(obj->getVida()-10);
            cout << "vida objetivo: " << obj->getVida() << endl;
        }else{
            cout << "ataque bloquedo" << endl;
        }
        tcd = clock.getElapsedTime().asSeconds();
        //cooldown en progreso

    }


private:
    bool range = true;
    int fataque, fbloqueo, fesquive;
    int ultimaAccion = 0.0;
    Boxeador* objetivo;
    Clock clock;
    Clock cd;
    int tcd;
};


#endif //CMAKESFMLPROJECT_ENEMY_H
