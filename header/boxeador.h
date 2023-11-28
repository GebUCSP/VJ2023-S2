#ifndef VJ2023_S2_2_BOXEADOR_H
#define VJ2023_S2_2_BOXEADOR_H

#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"

class Boxeador{
protected:
    std::string nombre;
    int vida, energia, dmg, lastAction;
    //attack, block, dodge
    std::vector<bool>states = {false,false,false};
    //up, der, back, izq
    std::vector<bool>directions = {false,false, false,false};
    //reloj propio
    sf::Clock clock1;

    sf::Sprite image;

    std::vector<sf::Texture>t_golpes;
    std::vector<sf::Texture>t_states;

    sf::Sprite s_states;
    std::vector<int>tiempos_g;
    std::vector<int>tiempos_t;

public:
    sf::Sprite s_golpes;
    Boxeador(std::string ,int, int, int);

    ~Boxeador();

    virtual void drawMe(sf::Sprite&, sf::Texture&);
    virtual void inputs(sf::Keyboard::Key, bool) = 0;
    virtual void timer(Boxeador*)=0;
    virtual void check1()=0;

     void attack(Boxeador*);

    void changeStates(int, bool);
    void changeDirections(int, bool);

    sf::Sprite& getSprite();
    std::string getNombre();
    int getVida();
    int getEnergia();
    int getDmg();
    bool getStates(int);
    bool getDirections(int);


    void setNombre(std::string);
    void setVida(int);
    void setEnergia(int);
    void setDmg(int);

    //BORRAR
    void print();

};


#endif //VJ2023_S2_2_BOXEADOR_H
