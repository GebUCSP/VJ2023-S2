#ifndef CMAKESFMLPROJECT_ENEMY_H
#define CMAKESFMLPROJECT_ENEMY_H

#include "../boxeador/Boxeador.h"
#include "SFML/System/Clock.hpp"

class Enemigo: public Boxeador{
public:
    Enemigo(Boxeador*,std::string,int,int,int,int);
    int random();
    void timer();
    void accionRandom(int);
    void attack();

private:
    bool range = true;
    int frecuencia;
    int ultimaAccion = 0.0;
    Boxeador *objetivo;
    sf::Clock clock;

};


#endif //CMAKESFMLPROJECT_ENEMY_H
