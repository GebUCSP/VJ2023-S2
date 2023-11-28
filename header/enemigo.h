#ifndef CMAKESFMLPROJECT_ENEMIGO_H
#define CMAKESFMLPROJECT_ENEMIGO_H

#include <random>
#include <chrono>

#include "SFML/System/Clock.hpp"

#include "../header/boxeador.h"

class Enemigo: public Boxeador{
private:
    sf::Vector2f posInitial;
    int numRandom;
    int frecuenciaMin, frecuenciaMax;
public:
    Enemigo(std::string, int, int, int, int,int);

    void inputs(sf::Keyboard::Key, bool) override;
    void timer(Boxeador*) override;

    int random(int a, int b);
    std::string randomDirection();
    void move(std::string);


};

#endif //CMAKESFMLPROJECT_ENEMIGO_H
