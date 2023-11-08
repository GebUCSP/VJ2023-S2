#ifndef CMAKESFMLPROJECT_BOXEADOR_H
#define CMAKESFMLPROJECT_BOXEADOR_H

#include <string>
#include <vector>

class Boxeador
{
protected:
    //Estados del jugador
    //attack, block, dodge
    std::vector<bool>states = {false, false, false};
    //Direcciones del jugador
    //up, der, back, izq
    std::vector<bool>directions = {false,false,false,false};
    std::string nombre;
    int vida, energia, dmg;
    //Determina si el jugador realizo una accion primero
    bool range = false;

private:
    //Clase amiga con juego
    friend class Juego;

public:
    Boxeador(std::string, int, int, int);
    void setVida(int);
    void setEnergia(int);
    int getVida();
    int getEnergia();
    bool getRange() const;
    void changeRange();

};

#endif //CMAKESFMLPROJECT_BOXEADOR_H