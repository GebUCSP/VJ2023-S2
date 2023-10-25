#ifndef CMAKESFMLPROJECT_BOXER_H
#define CMAKESFMLPROJECT_BOXER_H

#include <iostream>
#include "SFML/Graphics.hpp"

using namespace sf;
using namespace std;

class Boxeador
{
public:
    Boxeador(string _nombre, int _vida, int _energia,int _cd = 1.0, int _dmg = 10) :
            nombre { _nombre },
            vida { _vida },
            energia { _energia },
            tcd {_cd},
            dmg {_dmg}
    {
        if (_vida <= 0)
            vida = 100;
        if (_energia <= 0)
            energia = 100;
    };

    int getVida()
    {
        return vida;
    }
    int getEnergia()
    {
        return energia;
    }

    void setVida(int newVida)
    {
        vida = newVida;
    }

    void setEnergia(int newEnergia)
    {
        energia = newEnergia;
    }


    bool getRange(){
        return range;
    }


    void setRange(bool newRange){
        range = newRange;
    }


    int dmg;
    bool block = false;
    bool attack = false;
    bool dodge = false;
    bool izq=false, der=false, up=false, back=false;

protected:

    string nombre;
    int vida, energia, tcd;
    bool range = false;
    //status: neutro (0), atacando(1), bloqueando(2), esquivando(3), b&a(4), b&e(5)
};



#endif //CMAKESFMLPROJECT_BOXER_H
