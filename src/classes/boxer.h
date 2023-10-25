#ifndef CMAKESFMLPROJECT_BOXER_H
#define CMAKESFMLPROJECT_BOXER_H

#include <iostream>
#include "SFML/Graphics.hpp"

using namespace sf;
using namespace std;

class Boxeador
{
public:
    Boxeador(string _nombre, int _vida, int _energia) :
            nombre { _nombre },
            vida { _vida },
            energia { _energia }
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
    string getStatus()
    {
        return status;
    }

    void setVida(int newVida)
    {
        vida = newVida;
    }

    void setEnergia(int newEnergia)
    {
        energia = newEnergia;
    }

    void setStatus(string newStatus)
    {
        status = newStatus;
    }


protected:
    string nombre;
    int vida, energia;
    string status;
    //status: neutro (0), atacando(1), bloqueando(2), esquivando(3), b&a(4), b&e(5)
};



#endif //CMAKESFMLPROJECT_BOXER_H
