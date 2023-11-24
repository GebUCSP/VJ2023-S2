#ifndef CMAKESFMLPROJECT_ENEMIGO_H
#define CMAKESFMLPROJECT_ENEMIGO_H

#include <random>
#include <chrono>

#include "SFML/System/Clock.hpp"

#include "../header/boxeador.h"

class Enemigo: public Boxeador{
private:
    int numRandom;
public:
    Enemigo(std::string, int, int, int);

    void drawMe() override;
    void inputs(sf::Keyboard::Key, bool) override;
    void timer(Boxeador*) override;

    int random();


};

#endif //CMAKESFMLPROJECT_ENEMIGO_H
