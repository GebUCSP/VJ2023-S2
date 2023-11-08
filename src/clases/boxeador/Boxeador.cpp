#include "Boxeador.h"

//Constructor de Boxeador
Boxeador::Boxeador(std::string _nombre, int _vida, int _energia, int _dmg = 10)
{
    //Reinicia el tiempo en el que no puede golpear el enemigo
    cd.restart();

    this->nombre = _nombre;
    this->dmg = _dmg;

    //Coloca una vida minima a cumplir
    if(_vida <= 0){
        this->vida = 100;
    }else{
        this->vida = _vida;
    }

    //Coloca una energia minima a cumplir
    if(_energia <= 0){
        this->energia = 100;
    }else{
        this->energia = _energia;
    }

}

//Cambiar vida
void Boxeador::setVida(int _vida)
{
    this->vida = _vida;
}

//Conseguir vida
int Boxeador::getVida() {
    return vida;
}

//Conseguir energia
int Boxeador::getEnergia() {
    return energia;
}

//Cambiar energia
void Boxeador::setEnergia(int _energia)
{
    this->energia = _energia;
}

//Conseguir el rango
bool Boxeador::getRange() const
{
    return range;
}

//cambiar el rango
void Boxeador::changeRange()
{
    this->range = !this->getRange();
}

void Boxeador::stun(){
        int cooldown = cd.getElapsedTime().asSeconds();
        if(cooldown > 3) {
            this->changeRange();
            cd.restart();
        }
}

bool Boxeador::getStates(int index) const {
    return states[index];
}