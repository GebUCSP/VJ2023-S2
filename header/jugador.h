#ifndef CMAKESFMLPROJECT_JUGADOR_H
#define CMAKESFMLPROJECT_JUGADOR_H

#include "SFML/Graphics.hpp"

#include "boxeador.h"

class Jugador: public Boxeador{
    std::vector<std::string>t_golpes_dir = {"img/player/punching_izquierda.png","img/player/jab.png","img/player/punching_derecha.png"};
    std::vector<int>tiempos_g_temp = {5,7,4};
    std::vector<int>tiempos_g = tiempos_g_temp;
    bool OK = false;
public:


    Jugador(std::string _nombre, int _vida, int _energia, int _dmg);

    void inputs(sf::Keyboard::Key, bool) override;
    void timer(Boxeador*) override;
    void check1() override;
    void check2() ;
};

#endif //CMAKESFMLPROJECT_JUGADOR_H
