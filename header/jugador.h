#ifndef CMAKESFMLPROJECT_JUGADOR_H
#define CMAKESFMLPROJECT_JUGADOR_H

#include "SFML/Graphics.hpp"

#include "boxeador.h"

class Jugador: public Boxeador{
private:
    sf::Vector2f posInitial;


public:

    Jugador(std::string _nombre, int _vida, int _energia, int _dmg);

    void inputs(sf::Keyboard::Key, bool) override;
    void timer(Boxeador*) override;

    void movement() override;

};

#endif //CMAKESFMLPROJECT_JUGADOR_H
