#ifndef CMAKESFMLPROJECT_ENEMIGO_H
#define CMAKESFMLPROJECT_ENEMIGO_H

#include <random>
#include <chrono>

#include "SFML/System/Clock.hpp"

#include "../header/boxeador.h"

class Enemigo: public Boxeador{
private:
    int numRandom;
    int frecuenciaMin, frecuenciaMax;
public:
    Enemigo(std::string, int, int, int, int,int,bool);

    void inputs(sf::Keyboard::Key, bool) override;

    int random(int a, int b);
    void movement() override;


};

#endif //CMAKESFMLPROJECT_ENEMIGO_H
