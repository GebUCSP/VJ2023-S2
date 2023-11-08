#include "Boxeador.h"

Boxeador::Boxeador(std::string _nombre, int _vida, int _energia, int _dmg = 10)
{
    this->nombre = _nombre;
    this->dmg = _dmg;

    if(_vida <= 0){
        this->vida = 100;
    }else{
        this->vida = _vida;
    }

    if(_vida <= 0){
        this->energia = 100;
    }else{
        this->energia = _energia;
    }

}

void Boxeador::setVida(int _vida)
{
    this->vida = _vida;
}

int Boxeador::getVida() {
    return vida;
}

int Boxeador::getEnergia() {
    return energia;
}

void Boxeador::setEnergia(int _energia)
{
    this->energia = _energia;
}

bool Boxeador::getRange() const
{
    return range;
}

void Boxeador::changeRange()
{
    this->range = !this->getRange();
}