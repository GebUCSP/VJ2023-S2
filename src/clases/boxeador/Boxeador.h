#ifndef CMAKESFMLPROJECT_BOXEADOR_H
#define CMAKESFMLPROJECT_BOXEADOR_H

#include <string>
#include <vector>

class Boxeador
{
protected:
    //attack, block, dodge
    std::vector<bool>states = {false, false, false};
    //up, der, back, izq
    std::vector<bool>directions = {false,false,false,false};
    std::string nombre;
    int vida, energia, dmg;
    bool range = false;

private:
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