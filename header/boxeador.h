#ifndef VJ2023_S2_2_BOXEADOR_H
#define VJ2023_S2_2_BOXEADOR_H

#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"

class Boxeador{
protected:
    sf::Texture texture;
    sf::Sprite sprite;

    //////////////////
    sf::Texture texture1;
    sf::Texture texture2;

    ///////////////

    std::string nombre;
    int vida, energia, dmg, lastAction;
    float dirImg;
    //attack, block
    std::vector<bool>states = {false,false};
    //up, der, back, izq
    std::vector<bool>directions = {false,false, false,false};
    //reloj propio
    sf::Clock clock1;

    sf::Font font;
    sf::Text nombre_f;
    sf::Text vida_f;
    sf::Text energia_f;

    sf::Vector2f posInitial;


public:
    Boxeador(std::string ,int, int, int);

    ~Boxeador();


    virtual void inputs(sf::Keyboard::Key, bool) = 0;
    virtual void timer(Boxeador*)=0;

    void updateIu();
    void iu(sf::RenderWindow* );

    void attack(Boxeador*);
    virtual void movement() = 0;

    void changeStates(int, bool);
    void changeDirections(int, bool);

    std::string getNombre();
    sf::Sprite getSprite();
    sf::Texture getTexture();
    int getVida();
    int getEnergia();
    int getDmg();
    bool getStates(int);
    bool getDirections(int);


    void returnBase();


    void setPos();
    void setNombre(std::string);
    void setVida(int);
    void setEnergia(int);
    void setDmg(int);

    //BORRAR
    void print();

};


#endif //VJ2023_S2_2_BOXEADOR_H
