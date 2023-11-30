#ifndef VJ2023_S2_2_BOXEADOR_H
#define VJ2023_S2_2_BOXEADOR_H

#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"

class Boxeador{
protected:
    sf::Texture texture;
    sf::Sprite sprite;
    

    std::vector<sf::Texture> textures;

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
    Boxeador(std::string ,int, int, int, bool);

    ~Boxeador();


    virtual void inputs(sf::Keyboard::Key, bool) = 0;

    void updateIu();
    void iu(sf::RenderWindow* );

    virtual void movement() = 0;
    void attack(Boxeador*);

    void changeStates(int, bool);
    void changeDirections(int, bool);

    sf::Sprite getSprite();
    sf::Texture getTexture();
    int getVida() const;
    int getEnergia() const;
    int getDmg() const;
    bool getStates(int) const;
    bool getDirections(int) const;

    void setVida(int);
    void setEnergia(int);

};


#endif //VJ2023_S2_2_BOXEADOR_H
